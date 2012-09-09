#ifndef MEMORYMODEL_H
#define MEMORYMODEL_H

#include <QtGlobal>

struct MemoryModelPrivate;

class MemoryModel
{
public:
    enum Size
    {
        INT8_SIZE,
        INT16_SIZE,
        INT32_SIZE,
        INT64_SIZE,

        FLOAT_SIZE,
        DOUBLE_SIZE,

        ADDRESS_SIZE
    };

    enum Align
    {
        INT8_ALIGN,
        INT16_ALIGN,
        INT32_ALIGN,
        INT64_ALIGN,

        FLOAT_ALIGN,
        DOUBLE_ALIGN,

        ADDRESS_ALIGN
    };

    enum ByteOrder
    {
        LittleEndian = 0x4321,
        BigEndian = 0x1234
    };

public:
    MemoryModel(MemoryModelPrivate const &d);

    quint8 sizeInBytes(Size size) const;
    quint8 alignmentInBytes(Align align) const;
    MemoryModel::ByteOrder byteOrder() const;

    static MemoryModel const AVR32;
    static MemoryModel const I386;
    static MemoryModel const AMD64;

private:
    MemoryModelPrivate const &d;
};

#endif // MEMORYMODEL_H
