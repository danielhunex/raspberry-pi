/*  GIMP header image file format (INDEXED): C:\Users\Daniel\Downloads\1200px-Chelsea_FC.svg.h  */
#include <bcm2835.h>
//static u_int8_t width = 64;
//static u_int8_t height = 32;

/*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit*/
static u_int16_t chelseaFC[24][48] = {{0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x78, 0xff, 0x97, 0xff, 0xb8, 0xff, 0x97, 0xff, 0x97, 0xff, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdd, 0xff, 0x76, 0xff, 0xd5, 0xee, 0x77, 0x7c, 0x55, 0x4b, 0xb3, 0x3a, 0xf4, 0x42, 0xb6, 0x5b, 0x17, 0x9d, 0xf5, 0xf6, 0x75, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x77, 0xff, 0xf7, 0xee, 0xd4, 0x3a, 0x0c, 0x00, 0xfa, 0xb5, 0x54, 0x53, 0xce, 0x00, 0xfa, 0xb5, 0x6d, 0x00, 0xb2, 0x3a, 0xd6, 0x63, 0xb6, 0x5b, 0x35, 0xff, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x55, 0xff, 0xb8, 0xad, 0x0d, 0x00, 0x38, 0x95, 0xb0, 0x11, 0xd7, 0x84, 0x56, 0x74, 0x2f, 0x01, 0xd8, 0x8c, 0x4d, 0x00, 0x1a, 0xbe, 0x11, 0x22, 0xce, 0x00, 0xb3, 0x32, 0xb7, 0xde, 0x78, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x76, 0xff, 0x78, 0xa5, 0x2f, 0x01, 0x7b, 0xc6, 0x76, 0x7c, 0x7b, 0xc6, 0x92, 0x3a, 0x18, 0x95, 0xd2, 0x3a, 0xb7, 0x84, 0x94, 0x5b, 0x16, 0x74, 0xd5, 0x63, 0x5b, 0xc6, 0xd7, 0x8c, 0x30, 0x01, 0xf8, 0xe6, 0xbb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xdc, 0xff, 0x97, 0xde, 0x54, 0x4b, 0xee, 0x00, 0x94, 0x5b, 0xd5, 0x63, 0x6f, 0x09, 0xb2, 0x3a, 0x18, 0x95, 0x1d, 0xdf, 0x79, 0xa5, 0x39, 0x9d, 0x51, 0x2a, 0x94, 0x5b, 0x15, 0x6c, 0x31, 0x22, 0x8d, 0x00, 0xef, 0x00, 0x75, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0x96, 0xff, 0x73, 0x2a, 0x36, 0x74, 0x8d, 0x00, 0x72, 0x2a, 0x11, 0x22, 0xf0, 0x19, 0x18, 0x95, 0xff, 0xff, 0xf8, 0x94, 0xce, 0x00, 0xb5, 0x63, 0xff, 0xff, 0xd5, 0x63, 0x16, 0x6c, 0xb7, 0x84, 0xb7, 0x84, 0x99, 0xa5, 0x37, 0x74, 0x56, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0x75, 0xde, 0x2d, 0x00, 0xdc, 0xd6, 0x95, 0x5b, 0x97, 0x84, 0x79, 0xa5, 0x8f, 0x11, 0xdf, 0xff, 0x9f, 0xf7, 0x11, 0x22, 0xce, 0x00, 0xf2, 0x4a, 0x97, 0xf5, 0xff, 0xff, 0xb5, 0x63, 0x6d, 0x00, 0x5e, 0xef, 0xd0, 0x19, 0xcf, 0x00, 0x96, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0x76, 0xff, 0x98, 0x7c, 0xee, 0x00, 0x2f, 0x01, 0x13, 0x4b, 0x51, 0x2a, 0xff, 0xff, 0x0c, 0x00, 0xb5, 0x63, 0x59, 0x9d, 0xae, 0x00, 0x90, 0x11, 0xbf, 0xf7, 0xbf, 0xef, 0x0b, 0x00, 0xff, 0xff, 0x11, 0x22, 0xd5, 0x63, 0xee, 0x00, 0xce, 0x00, 0xd5, 0xbd, 0xfe, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0x97, 0xff, 0xd3, 0x3a, 0x0f, 0x01, 0x2f, 0x01, 0xad, 0x00, 0x1b, 0xbe, 0xff, 0xff, 0x94, 0x5b, 0xd3, 0x3a, 0xae, 0x00, 0x4f, 0x09, 0xee, 0x00, 0x96, 0x84, 0x56, 0x7c, 0x76, 0x7c, 0xff, 0xff, 0xf5, 0x6b, 0xae, 0x00, 0x2f, 0x01, 0xee, 0x00, 0xd8, 0x84, 0x77, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xb8, 0xff, 0xf1, 0x11, 0x10, 0x42, 0x72, 0xab, 0x8d, 0x00, 0x7e, 0xef, 0xff, 0xff, 0x76, 0x84, 0x1d, 0xdf, 0x31, 0x22, 0x0f, 0x01, 0xee, 0x00, 0xff, 0xff, 0x4d, 0x00, 0xf0, 0x19, 0xff, 0xff, 0x9a, 0xa5, 0x0e, 0x01, 0xb2, 0xcb, 0x4f, 0x09, 0xf6, 0x63, 0x97, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xb8, 0xff, 0xf1, 0x19, 0x10, 0x3a, 0x11, 0x9b, 0x8d, 0x00, 0x9e, 0xef, 0xff, 0xff, 0x6f, 0x09, 0x4d, 0x00, 0xee, 0x00, 0xb2, 0x3a, 0xad, 0x00, 0x5e, 0xef, 0x56, 0x74, 0x1a, 0xbe, 0xff, 0xff, 0x79, 0xa5, 0xee, 0x00, 0x71, 0xb3, 0x2f, 0x09, 0xf6, 0x63, 0x97, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0x97, 0xff, 0xd4, 0x3a, 0x0f, 0x01, 0xef, 0x00, 0xae, 0x00, 0xfa, 0xb5, 0xff, 0xff, 0x51, 0x2a, 0xfd, 0xde, 0x9c, 0xce, 0xaf, 0x19, 0xee, 0x00, 0x13, 0x4b, 0x38, 0x9d, 0x54, 0x53, 0xff, 0xff, 0xf5, 0x63, 0xce, 0x00, 0x0f, 0x01, 0xee, 0x00, 0xd8, 0x8c, 0x77, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0x77, 0xff, 0x98, 0x7c, 0xee, 0x00, 0xd5, 0x63, 0x51, 0x2a, 0x51, 0x2a, 0xff, 0xff, 0x15, 0x74, 0xff, 0xff, 0x8d, 0x00, 0xb0, 0x11, 0x90, 0x09, 0x11, 0x22, 0x18, 0x95, 0xff, 0xff, 0xff, 0xff, 0xae, 0x00, 0xd2, 0x3a, 0x92, 0x32, 0xae, 0x00, 0xd5, 0xc5, 0xfe, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0x95, 0xe6, 0x8e, 0x00, 0xb0, 0x11, 0x53, 0x53, 0xad, 0x00, 0x5b, 0xc6, 0x92, 0x3a, 0xff, 0xff, 0xf3, 0x42, 0xd5, 0x63, 0xff, 0xff, 0xd0, 0x11, 0x56, 0x7c, 0xff, 0xff, 0x74, 0x53, 0x0e, 0x01, 0xd5, 0x63, 0x13, 0x4b, 0xef, 0x00, 0xb6, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0x95, 0xff, 0xb4, 0x32, 0xb2, 0x3a, 0x11, 0x22, 0xb2, 0x3a, 0x6d, 0x00, 0xb7, 0x84, 0x31, 0x22, 0x2c, 0x00, 0xff, 0xff, 0x59, 0x9d, 0x4f, 0x01, 0xdc, 0xd6, 0xd5, 0x63, 0x6d, 0x00, 0xd3, 0x42, 0xf3, 0x42, 0x6d, 0x00, 0xd8, 0x8c, 0x76, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xdd, 0xff, 0x17, 0xf7, 0x6e, 0x00, 0xd0, 0x19, 0xd5, 0x63, 0xf3, 0x42, 0xce, 0x00, 0x6f, 0x09, 0x56, 0x7c, 0xbc, 0xd6, 0x76, 0x7c, 0x10, 0x22, 0x0f, 0x01, 0x90, 0x09, 0x54, 0x53, 0x90, 0x11, 0x72, 0x32, 0x91, 0x09, 0x75, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x77, 0xff, 0x18, 0xbe, 0x2d, 0x00, 0xb2, 0x3a, 0xb2, 0x3a, 0xf5, 0x63, 0xb2, 0x3a, 0x2f, 0x01, 0xae, 0x00, 0xee, 0x00, 0xb0, 0x11, 0x0f, 0x01, 0x33, 0x4b, 0x4f, 0x09, 0x13, 0x43, 0xaf, 0x00, 0x17, 0xf7, 0xbc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x55, 0xff, 0x39, 0xc6, 0x8e, 0x00, 0x0e, 0x01, 0xd0, 0x19, 0x97, 0x84, 0xd2, 0x3a, 0x36, 0x74, 0xf3, 0x42, 0x34, 0x4b, 0x2f, 0x01, 0x92, 0x32, 0xb0, 0x11, 0x50, 0x01, 0x17, 0xf7, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x78, 0xff, 0x36, 0xf7, 0x76, 0x53, 0x6e, 0x00, 0x70, 0x09, 0x90, 0x11, 0xd0, 0x19, 0x51, 0x2a, 0xb0, 0x11, 0x70, 0x09, 0xae, 0x00, 0x77, 0x7c, 0x75, 0xff, 0xbb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x75, 0xff, 0x15, 0xf7, 0x37, 0x9d, 0xd6, 0x63, 0x14, 0x43, 0x34, 0x4b, 0x37, 0x6c, 0x96, 0xad, 0x76, 0xff, 0x56, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0xff, 0x77, 0xff, 0x97, 0xff, 0x97, 0xff, 0x77, 0xff, 0xdc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
									 {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}};