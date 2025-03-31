/* When working with color values it can sometimes be useful to extract the 
 * individual red, green, and blue (RGB) component values for a color. Implement 
 * a function that meets these requirements:
Accepts a case-insensitive hexadecimal color string as its parameter (ex. "#FF9933" or "#ff9933")
Returns a Map<String, int> with the structure {r: 255, g: 153, b: 51} where r, g, and b range from 
0 through 255 Note: your implementation does not need to support the shorthand form of hexadecimal 
notation (ie "#FFF")
Example
"#FF9933" --> {r: 255, g: 153, b: 51} */
typedef struct {
    int r, g, b;
} rgb;

int hex_str_to_int(const char hex_char) {
  return hex_char == 'F' || hex_char == 'f' ? 15 :
         hex_char == 'E' || hex_char == 'e' ? 14 :
         hex_char == 'D' || hex_char == 'd' ? 13 :
         hex_char == 'C' || hex_char == 'c' ? 12 :
         hex_char == 'B' || hex_char == 'b' ? 11 :
         hex_char == 'A' || hex_char == 'a' ? 10 :
         hex_char == '9' ? 9 :
         hex_char == '8' ? 8 :
         hex_char == '7' ? 7 :
         hex_char == '6' ? 6 :
         hex_char == '5' ? 5 :
         hex_char == '4' ? 4 :
         hex_char == '3' ? 3 :
         hex_char == '2' ? 2 :
         hex_char == '1' ? 1 : 0;
}

rgb hex_str_to_rgb(const char *hex_str) {
  rgb hex_rgb;
  hex_rgb.r = (hex_str_to_int(hex_str[1]) * 16) + hex_str_to_int(hex_str[2]);
  hex_rgb.g = (hex_str_to_int(hex_str[3]) * 16) + hex_str_to_int(hex_str[4]);
  hex_rgb.b = (hex_str_to_int(hex_str[5]) * 16) + hex_str_to_int(hex_str[6]);
  return hex_rgb;
}
