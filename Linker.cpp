#include "Linker.h"

#include "Struct_ClassTable.h"
#include "MemoryWriter.h"
#include "DryRunWriter.h"
#include "MemoryMapWriter.h"

#include <QTextStream>
#include <QDebug>

#include <cstdio>

struct LinkerPrivate
{
    JVMConfig config;
    JVMClassList classList;

    LinkerPrivate(JVMConfig config, JVMClassList classList)
        : config(config)
        , classList(classList)
    {
    }
};

Linker::Linker(JVMConfig config, JVMClassList classList)
    : d_ptr(new LinkerPrivate(config, classList))
{
}

Linker::~Linker()
{
}

void Linker::link()
{
    Q_D(Linker);
    qDebug("linking...");

    quint32 const baseAddress = d->config.baseAddress();

    Struct_ClassTable classTable(d->classList, baseAddress, d->config.nativeInterface());

#if 0
    DryRunWriter drw;
    classTable.write(drw);
    qFatal("%u", drw.memorySize());
#endif

    QString map;
    QTextStream ts(&map);
    classTable.printMemoryMap(ts);

    {
        FILE *out = fopen("memory.log", "w");
        fprintf(out, "%s", map.toUtf8().constData());
        fclose(out);
    }

    MemoryMapWriter memMap(baseAddress);
    classTable.write(memMap);
    memMap.flush();
    {
        QFile out("new.xml");
        out.open(QFile::WriteOnly);
        out.write(memMap.data());
    }

    MemoryWriter writer(baseAddress);
    classTable.write(writer);
    {
        QFile out("new.bin");
        out.open(QFile::WriteOnly);
        out.write(writer.data());
    }

    qDebug("linking done: %d bytes", writer.size());
}
