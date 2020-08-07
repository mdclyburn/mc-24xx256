/** @file
 *
 * Read and write operations.
 */

#ifndef MDL_MC24XX256_OPS_H
#define MDL_MC24XX256_OPS_H

#include <stdint.h>

namespace mardev::mc24xx256
{
    /** Start a read operation.
     *
     * Perform prerequisite communication to a read operation.
     * This should be called before calling read().
     *
     * \param chip_select Chip select address (3 least significant bits).
     * \param address 15-bit address to start the read at (MSB is ignored).
     *
     * \returns True if the peripheral is ready.
     */
    bool begin_read(const uint8_t chip_select,
                    const uint16_t address);

    /** Start a write operation.
     *
     * Perform prerequisite communication to a write operation.
     * This should be called before calling write().
     *
     * \param chip_select Chip select address (3 least significant bits).
     * \param address 15-bit address to start the write at (MSB is ignored).
     */
    bool begin_write(const uint8_t chip_select,
                     const uint16_t address);

    /** Read from the 24XX256.
     *
     * Read the specified number of bytes from memory.
     * Reading beyond the 64-byte page boundary wraps to the beginning of the page.
     *
     * \param count Number of bytes to read (up to 64).
     * \param buffer Buffer to store read bytes in.
     */
    void read(const uint8_t count,
              uint8_t* const buffer);


    /** Write to the 24XX256.
     *
     * Write the specified number of bytes to memory.
     * Writing beyond the 64-byte page boundary wraps to the beginning of the page.
     *
     * \param count Number of bytes to write (up to 64).
     * \param buffer Data to write to memory.
     */
    void write(const uint8_t count,
               const uint8_t* const buffer);
}

#endif
