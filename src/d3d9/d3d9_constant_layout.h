#pragma once

#include <cstdint>

#include "d3d9_caps.h"

namespace dxvk {

  struct D3D9ConstantLayout {
    uint32_t floatCount;
    uint32_t intCount;
    uint32_t boolCount;
    uint32_t bitmaskCount;

    uint32_t floatSize()     const { return floatCount   * 4 * sizeof(float); }
    uint32_t intSize()       const { return intCount     * 4 * sizeof(int); }
    uint32_t bitmaskSize()   const { return bitmaskCount * 1 * sizeof(uint32_t); }

    uint32_t floatOffset()   const { return 0; }
    uint32_t intOffset()     const { return floatOffset() + floatSize(); }
    uint32_t bitmaskOffset() const { return intOffset()   + intSize(); }

    uint32_t totalSize()     const { return floatSize() + intSize() + bitmaskSize(); }
  };

}