#include <usci-i2c.h>

#include "ops.h"

namespace i2c = mardev::msp430::usci::i2c;

namespace mardev::mc24xx256
{
    /** @private
     * Form the control byte for a read operation.
     *
     * \param cs Chip select address (3 least significant bits only).
     */
    inline uint8_t __gen_control_byte_read(const uint8_t cs)
    {
        return 0b10100001 | (cs & 0b1110);
    }

    /** @private
     *
     * Form the control byte for a write operation.
     *
     * \param cs Chip select address (3 least significant bits only).
     */
    inline uint8_t __gen_control_byte_write(const uint8_t cs)
    {
        return 0b10100000 | (cs & 0b1110);
    }

    bool begin_read(const uint8_t chip_select,
                    const uint16_t address)
    {
        i2c::set_periph_address(__gen_control_byte_read(chip_select));
        return i2c::read_begin();
    }

    bool begin_write(const uint8_t chip_select,
                     const uint16_t address)
    {
        i2c::set_periph_address(__gen_control_byte_write(chip_select));
        return i2c::write_begin();
    }

    void read(const uint8_t count,
              uint8_t* const buffer)
    {
        for(uint8_t i = 0; i < count; i++)
        {
            buffer[i] = i2c::read();
        }

        i2c::read_end();

        return;
    }

    void write(const uint8_t count,
               const uint8_t* const buffer)
    {
        for(uint8_t i = 0; i < count; i++)
        {
            i2c::write(buffer[i]);
        }

        i2c::write_end();

        return;
    }
}
