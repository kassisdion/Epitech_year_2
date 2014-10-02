#ifndef CORE_MAPS_H_
#define CORE_MAPS_H_

#define DECLARE_MAP(name) \
  extern const char *map_##name##_data; \
  extern unsigned int map_##name##_width; \
  extern unsigned int map_##name##_height;

#define DEFINE_MAP(name, width, height, data) \
  const char *map_##name##_data = data; \
  unsigned int map_##name##_width = width; \
  unsigned int map_##name##_height = height;

DECLARE_MAP(test)
DECLARE_MAP(full)

#endif /* CORE_MAPS_H_ */
