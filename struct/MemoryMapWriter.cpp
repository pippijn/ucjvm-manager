#include "MemoryMapWriter.h"

MemoryMapWriter::MemoryMapWriter(quint32 baseAddress)
    : DataWriter(baseAddress)
    , stream(&array)
    , level(0)
{
    stream << hex;
}


void MemoryMapWriter::write8(quint8 value)
{
    indent();
    stream << "<u8>" << value << "</u8>\n";
}

void MemoryMapWriter::write16(quint16 value)
{
    indent();
    stream << "<u16>" << value << "</u16>\n";
}

void MemoryMapWriter::write32(quint32 value)
{
    indent();
    stream << "<u32>" << value << "</u32>\n";
}

void MemoryMapWriter::write64(quint64 value)
{
    indent();
    stream << "<u64>" << value << "</u64>\n";
}

void MemoryMapWriter::writeFloat(float value)
{
    indent();
    stream << "<float>" << value << "</float>\n";
}

void MemoryMapWriter::writeDouble(double value)
{
    indent();
    stream << "<double>" << value << "</double>\n";
}


void MemoryMapWriter::start(const char *section, quint32 address)
{
    sectionStack.append(section);
    indent();
    stream << "<" << section << " address='" << address << "'>\n";

    level++;
}

void MemoryMapWriter::end(const char *section, quint32 address)
{
    char const *popped = sectionStack.back();
    sectionStack.pop_back();
    Q_ASSERT(popped == section);

    level--;

    indent();
    stream << "</" << section << ">\n";
}


void MemoryMapWriter::indent()
{
    for (int i = 0; i < level; i++)
        stream << '\t';
}
