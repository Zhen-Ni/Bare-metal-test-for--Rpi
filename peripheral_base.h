#ifndef PERIPHERAL_BASE_H
#define PERIPHERAL_BASE_H

#include <cstdint>

typedef unsigned int size_t;

// Base address of peripherals for RPi
#define BCM_PERIPHERAL_BASE 0x3F000000


// Get access to the registers
#define ACCESS(offset) *(address() + (offset))
#define ACCESS64(offset) *(volatile uint64_t *)(address() + (offset))

class Peripheral {
  volatile uint32_t *address_p;

  Peripheral(const Peripheral &) = delete;
  Peripheral &operator=(const Peripheral &) = delete;
  
public:
  Peripheral(uint32_t base_address);
  volatile uint32_t *const &address() const {return address_p;}
};

Peripheral::Peripheral(uint32_t base_address): address_p(nullptr) {
  // Map the registers into memory
  address_p = reinterpret_cast<volatile uint32_t *>(base_address);
}



#endif
