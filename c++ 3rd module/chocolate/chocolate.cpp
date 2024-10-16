#include "chocolate.h"

bool CanBreakSlices(int height, int width, int slices_amount) {
    bool height_slice_check = slices_amount % height == 0 && slices_amount / height < width;
    bool width_slice_check = slices_amount % width == 0 && slices_amount / width < height;
    return height_slice_check || width_slice_check;
};
