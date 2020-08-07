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

    void begin_read(const uint8_t chip_select,
                    const uint16_t address)
    {
    }

    void begin_write(const uint8_t chip_select,
                     const uint16_t address)
    {
    }

    void read(const uint8_t count,
              uint8_t* const buffer,
              const uint8_t chip_select)
    {
    }

    void write(const uint8_t count,
               const uint8_t* const buffer,
               const uint8_t chip_select)
    {
    }
}
