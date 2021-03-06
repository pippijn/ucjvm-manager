#ifndef STRUCT_FIELD_TABLE_H
#define STRUCT_FIELD_TABLE_H

#include "Struct_Field.h"
class Fields;

#include <QList>

class Struct_Field_Table : public Struct
{
public:
    Struct_Field_Table(Fields const &fields);

    Struct_Field const *getField(QString name, QString descriptor) const;

    void computeFieldOffsets(quint16 staticBase, quint16 instanceBase);

    MemoryModel::Align alignment() const { return MemoryModel::ADDRESS_ALIGN; }
    void writeStruct(DataWriter &data) const;
    void writeData(DataWriter &data) const;
    quint32 computeMemoryMap(MemoryModel const &memoryModel, quint32 baseAddress);
    void printMemoryMap(QTextStream &ts) const;

    char const *typeName() const { return "Field_Table"; }

private:
    QList<Struct_Field> fields;
};

#endif // STRUCT_FIELD_TABLE_H
