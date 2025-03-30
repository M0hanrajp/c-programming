/* Write a function that returns the total surface area and volume of a box.

The given input will be three positive non-zero integers: width, height, and depth.

The output will be language dependant, so please check sample tests for the corresponding data type, (list, tuple, struct, query, et cetera). */
typedef struct AV_PAIR {
  unsigned area;
  unsigned volume;
} area_volume_pair;

area_volume_pair get_size(unsigned width, unsigned height, unsigned depth) {
  return (area_volume_pair) { .area = 2 * (width * height + depth * height + depth * width), 
                              .volume = width * height * depth};
}
