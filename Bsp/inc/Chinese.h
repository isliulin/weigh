/*���ļ�Ϊ16��16���������ֿ��ļ�,�ֵĺ���8�㹹��һ�ֽ�,��ߵ����ֽڵĸ�λ,�ַ������Ľǰ����Ͻǡ����Ͻǡ����½ǡ����½�ȡ��*/
/*���������Ժ������HZDotReader���ļ�,׷�Ӻ��ֵ�������,�벻Ҫ�޸Ļ���ɾ����ע��*/

#define  hzNum  102

unsigned char const hzIndex[204] = {
0xc9,0xee,0xdb,0xda,0xca,0xd0,0xd0,0xc0,0xc8,0xf0,0xb4,0xef,0xb5,0xe7,0xd7,0xd3,
0xd3,0xd0,0xcf,0xde,0xb9,0xab,0xcb,0xbe,0xb3,0xc9,0xc1,0xa2,0xd3,0xda,0xc4,0xea,
0xd4,0xc2,0xa3,0xac,0xd7,0xa8,0xd2,0xb5,0xb4,0xd3,0xca,0xc2,0xd2,0xba,0xbe,0xa7,
0xcf,0xd4,0xca,0xbe,0xc4,0xa3,0xbf,0xe9,0xb5,0xc4,0xd1,0xd0,0xb7,0xa2,0xa1,0xa2,
0xc9,0xfa,0xb2,0xfa,0xcf,0xfa,0xca,0xdb,0xb2,0xa2,0xcc,0xe1,0xb9,0xa9,0xc8,0xab,
0xcc,0xd7,0xbc,0xbc,0xca,0xf5,0xb7,0xbd,0xb0,0xb8,0xa1,0xa3,0xca,0xc7,0xba,0xab,
0xb9,0xfa,0xd6,0xd0,0xc7,0xf8,0xd3,0xf2,0xca,0xda,0xc8,0xa8,0xd7,0xdc,0xb4,0xfa,
0xc0,0xed,0xcc,0xa8,0xcd,0xe5,0xb2,0xc9,0xb9,0xe2,0xb4,0xf3,0xc2,0xbd,0xd6,0xb8,
0xb6,0xa8,0xc9,0xcc,0xce,0xaa,0xb9,0xe3,0xd3,0xc3,0xbb,0xa7,0xc8,0xd5,0xb1,0xbe,
0xc6,0xc1,0xba,0xcd,0xc6,0xb7,0xd2,0xd4,0xbc,0xb0,0xb8,0xf7,0xd6,0xd6,0xd6,0xdc,
0xb1,0xdf,0xc5,0xe4,0xbc,0xfe,0xa3,0xa8,0xc4,0xe6,0xb1,0xe4,0xc6,0xf7,0xb9,0xa4,
0xbf,0xd8,0xb0,0xe5,0xc1,0xac,0xbd,0xd3,0xcf,0xdf,0xc0,0xc2,0xb4,0xa5,0xc3,0xfe,
0xd7,0xaa,0xc7,0xfd,0xb6,0xaf,0xbf,0xa8,0xb5,0xc8,0xa3,0xa9 };

unsigned char const hzdot[3264] = {
/*��   CC9EE */
0x40,0x00,0x27,0xFE,0x24,0x04,0x01,0x20,0x81,0x18,0x56,0x08,0x50,0x40,0x10,0x40,
0x27,0xFC,0x20,0x40,0xC0,0xE0,0x41,0x58,0x46,0x4E,0x58,0x44,0x40,0x40,0x40,0x40,

/*��   CDBDA */
0x00,0x00,0x12,0x04,0x12,0x44,0x12,0x44,0xFE,0x44,0x12,0x44,0x12,0x44,0x12,0x44,
0x12,0x44,0x12,0x44,0x3A,0x44,0xC4,0x44,0x04,0x44,0x08,0x04,0x10,0x04,0x00,0x00,

/*��   CCAD0 */
0x02,0x00,0x01,0x00,0xFF,0xFE,0x01,0x00,0x01,0x00,0x1F,0xF8,0x11,0x08,0x11,0x08,
0x11,0x08,0x11,0x08,0x11,0x08,0x11,0x08,0x11,0x28,0x11,0x10,0x01,0x00,0x01,0x00,

/*��   CD0C0 */
0x03,0x40,0x3C,0x40,0x20,0x40,0x20,0x7E,0x20,0x84,0x3E,0xA8,0x25,0x20,0x24,0x20,
0x24,0x20,0x24,0x20,0x24,0x50,0x44,0x48,0x44,0x88,0x85,0x06,0x06,0x04,0x00,0x00,

/*��   CC8F0 */
0x00,0x20,0xF9,0x24,0x21,0x24,0x21,0x24,0x21,0xFC,0x20,0x00,0xFB,0xFE,0x20,0x40,
0x23,0xFE,0x22,0x52,0x2A,0x52,0x32,0x52,0xC2,0x52,0x02,0x52,0x02,0x4A,0x02,0x04,

/*��   CB4EF */
0x00,0x00,0x40,0x80,0x30,0x80,0x10,0x80,0x0F,0xFC,0x00,0x80,0x00,0x80,0xE0,0x80,
0x21,0x40,0x21,0x20,0x22,0x18,0x24,0x0C,0x28,0x08,0x50,0x02,0x8F,0xFC,0x00,0x00,

/*��   CB5E7 */
0x01,0x00,0x01,0x00,0x01,0x00,0x3F,0xF8,0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,
0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,0x01,0x02,0x01,0x02,0x00,0xFE,0x00,0x00,

/*��   CD7D3 */
0x00,0x00,0x3F,0xF0,0x00,0x20,0x00,0x40,0x00,0x80,0x01,0x00,0x01,0x00,0x01,0x04,
0xFF,0xFE,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x05,0x00,0x02,0x00,

/*��   CD3D0 */
0x01,0x00,0x01,0x00,0x7F,0xFE,0x02,0x00,0x04,0x00,0x0F,0xF0,0x18,0x10,0x28,0x10,
0x4F,0xF0,0x88,0x10,0x08,0x10,0x0F,0xF0,0x08,0x10,0x08,0x90,0x08,0x70,0x08,0x20,

/*��   CCFDE */
0x00,0x00,0xFB,0xF8,0x92,0x08,0x93,0xF8,0xA2,0x08,0xA2,0x08,0x93,0xF8,0x8A,0x80,
0x8A,0x48,0xAA,0x50,0x92,0x20,0x82,0x20,0x82,0x10,0x82,0x8E,0x83,0x04,0x82,0x00,

/*��   CB9AB */
0x00,0x00,0x04,0x40,0x06,0x40,0x04,0x40,0x08,0x20,0x08,0x10,0x10,0x18,0x22,0x0E,
0x43,0x04,0x02,0x00,0x04,0x20,0x08,0x10,0x11,0xF8,0x3F,0x18,0x10,0x10,0x00,0x00,

/*˾   CCBBE */
0x00,0x00,0x3F,0xFC,0x00,0x04,0x00,0x04,0x7F,0xE4,0x00,0x04,0x00,0x04,0x3F,0xC4,
0x20,0x44,0x20,0x44,0x3F,0xC4,0x20,0x44,0x20,0x04,0x00,0x14,0x00,0x08,0x00,0x00,

/*��   CB3C9 */
0x00,0xA0,0x00,0x90,0x00,0x80,0x3F,0xFE,0x20,0x80,0x20,0x80,0x3E,0x88,0x22,0x8C,
0x22,0x48,0x22,0x50,0x22,0x20,0x2A,0x60,0x44,0x92,0x41,0x0A,0x86,0x06,0x00,0x02,

/*��   CC1A2 */
0x02,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x7F,0xFC,0x00,0x20,0x00,0x30,0x10,0x20,
0x08,0x40,0x0C,0x40,0x04,0x40,0x04,0x80,0x00,0x80,0x01,0x04,0xFF,0xFE,0x00,0x00,

/*��   CD3DA */
0x00,0x00,0x3F,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFE,0x01,0x00,
0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x09,0x00,0x05,0x00,0x02,0x00,

/*��   CC4EA */
0x08,0x00,0x0F,0xFC,0x10,0x80,0x10,0x80,0x20,0x80,0x4F,0xF8,0x88,0x80,0x08,0x80,
0x08,0x80,0x08,0x80,0xFF,0xFE,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,

/*��   CD4C2 */
0x07,0xF0,0x04,0x10,0x04,0x10,0x04,0x10,0x07,0xF0,0x04,0x10,0x04,0x10,0x04,0x10,
0x07,0xF0,0x04,0x10,0x08,0x10,0x08,0x10,0x10,0x10,0x20,0x50,0x40,0x20,0x00,0x00,

/*��   CA3AC */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x10,0x00,0x20,0x00,0x00,0x00,

/*ר   CD7A8 */
0x01,0x00,0x01,0x00,0x3F,0xF8,0x02,0x00,0x02,0x00,0xFF,0xFE,0x04,0x00,0x08,0x20,
0x0F,0xF0,0x00,0x20,0x00,0x40,0x02,0x80,0x01,0x00,0x00,0x80,0x00,0x40,0x00,0x00,

/*ҵ   CD2B5 */
0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x44,0x44,0x46,0x24,0x4C,0x24,0x48,0x14,0x50,
0x1C,0x50,0x14,0x60,0x04,0x40,0x04,0x40,0x04,0x44,0xFF,0xFE,0x00,0x00,0x00,0x00,

/*��   CB4D3 */
0x08,0x40,0x08,0x40,0x08,0x40,0x08,0x40,0x08,0x40,0x08,0x40,0x08,0x40,0x08,0xA0,
0x14,0xA0,0x12,0x90,0x12,0x90,0x21,0x08,0x23,0x0C,0x42,0x06,0x84,0x04,0x08,0x00,

/*��   CCAC2 */
0x01,0x00,0xFF,0xFE,0x01,0x00,0x1F,0xF8,0x11,0x08,0x1F,0xF8,0x01,0x00,0x3F,0xF8,
0x01,0x08,0xFF,0xFE,0x01,0x08,0x3F,0xF8,0x01,0x08,0x09,0x00,0x05,0x00,0x02,0x00,

/*Һ   CD2BA */
0x40,0x40,0x20,0x20,0x27,0xFE,0x09,0x20,0x89,0x20,0x52,0x7C,0x52,0x44,0x16,0xA8,
0x2B,0x98,0x22,0x50,0xE2,0x20,0x22,0x30,0x22,0x50,0x22,0x88,0x23,0x0E,0x22,0x04,

/*��   CBEA7 */
0x00,0x00,0x0F,0xF0,0x08,0x10,0x0F,0xF0,0x08,0x10,0x0F,0xF0,0x08,0x10,0x00,0x00,
0x7E,0x7E,0x42,0x42,0x7E,0x7E,0x42,0x42,0x42,0x42,0x7E,0x7E,0x42,0x42,0x00,0x00,

/*��   CCFD4 */
0x00,0x00,0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x04,0x40,0x04,0x40,
0x44,0x48,0x24,0x48,0x14,0x50,0x14,0x60,0x04,0x40,0xFF,0xFE,0x00,0x00,0x00,0x00,

/*ʾ   CCABE */
0x00,0x00,0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x01,0x00,0x01,0x00,
0x11,0x20,0x11,0x10,0x21,0x08,0x41,0x0C,0x81,0x04,0x01,0x00,0x05,0x00,0x02,0x00,

/*ģ   CC4A3 */
0x20,0x90,0x20,0x90,0x27,0xFC,0x20,0x90,0xFB,0xF8,0x22,0x08,0x73,0xF8,0x6A,0x08,
0xA3,0xF8,0xA0,0x40,0x27,0xFE,0x20,0x40,0x20,0xA0,0x20,0x98,0x21,0x0E,0x26,0x04,

/*��   CBFE9 */
0x20,0x80,0x20,0x80,0x20,0x80,0x23,0xF8,0xF8,0x88,0x20,0x88,0x20,0x88,0x20,0x88,
0x2F,0xFE,0x20,0x80,0x39,0x40,0xE1,0x20,0x42,0x18,0x02,0x0E,0x04,0x04,0x08,0x00,

/*��   CB5C4 */
0x10,0x80,0x10,0x80,0x20,0x80,0x7C,0xFC,0x45,0x04,0x45,0x04,0x46,0x04,0x7C,0x84,
0x44,0x44,0x44,0x64,0x44,0x24,0x44,0x04,0x7C,0x04,0x44,0x28,0x40,0x10,0x00,0x00,

/*��   CD1D0 */
0x00,0x00,0xFD,0xFE,0x10,0x88,0x10,0x88,0x20,0x88,0x20,0x88,0x7B,0xFE,0x68,0x88,
0xA8,0x88,0x28,0x88,0x28,0x88,0x29,0x08,0x39,0x08,0x22,0x08,0x04,0x08,0x08,0x08,

/*��   CB7A2 */
0x02,0x00,0x22,0x40,0x22,0x30,0x22,0x10,0x7F,0xFE,0x24,0x00,0x04,0x00,0x07,0xE0,
0x0C,0x20,0x0A,0x20,0x0A,0x20,0x11,0x40,0x20,0x80,0x41,0x60,0x86,0x1C,0x18,0x08,

/*��   CA1A2 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x30,0x00,0x10,0x00,0x00,0x00,0x00,0x00,

/*��   CC9FA */
0x00,0x80,0x10,0xC0,0x10,0x80,0x10,0x88,0x1F,0xFC,0x20,0x80,0x20,0x80,0x40,0x88,
0x9F,0xFC,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x84,0x7F,0xFE,0x00,0x00,

/*��   CB2FA */
0x01,0x00,0x00,0x80,0x7F,0xFE,0x08,0x10,0x06,0x20,0x24,0x44,0x3F,0xFE,0x20,0x00,
0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x40,0x00,0x40,0x00,0x80,0x00,0x00,0x00,

/*��   CCFFA */
0x10,0x20,0x11,0x24,0x3E,0xA4,0x20,0x68,0x41,0xFC,0x7D,0x04,0x91,0x04,0x11,0xFC,
0xFD,0x04,0x11,0x04,0x11,0xFC,0x11,0x04,0x11,0x04,0x15,0x04,0x19,0x14,0x11,0x08,

/*��   CCADB */
0x09,0x00,0x08,0x80,0x1F,0xFC,0x10,0x80,0x3F,0xF8,0x50,0x80,0x9F,0xF8,0x10,0x80,
0x1F,0xFC,0x00,0x00,0x1F,0xF8,0x10,0x08,0x10,0x08,0x10,0x08,0x1F,0xF8,0x10,0x08,

/*��   CB2A2 */
0x10,0x10,0x08,0x18,0x06,0x10,0x04,0x20,0x7F,0xFC,0x04,0x20,0x04,0x20,0x04,0x20,
0x7F,0xFE,0x04,0x20,0x04,0x20,0x04,0x20,0x08,0x20,0x08,0x20,0x10,0x20,0x20,0x20,

/*��   CCCE1 */
0x10,0x00,0x11,0xF8,0x11,0x08,0xFD,0xF8,0x11,0x08,0x11,0xF8,0x18,0x00,0x37,0xFC,
0x50,0x40,0x92,0x40,0x12,0x7C,0x12,0x40,0x16,0x40,0x15,0xC0,0x58,0x7E,0x20,0x00,

/*��   CB9A9 */
0x10,0x00,0x19,0x10,0x11,0x10,0x21,0x10,0x37,0xFC,0x61,0x10,0xA1,0x10,0x21,0x10,
0x21,0x10,0x2F,0xFE,0x21,0x20,0x23,0x10,0x22,0x18,0x24,0x0C,0x28,0x08,0x20,0x00,

/*ȫ   CC8AB */
0x01,0x00,0x01,0x00,0x02,0x80,0x04,0x40,0x08,0x30,0x10,0x1C,0x3F,0xF8,0x41,0x00,
0x01,0x00,0x01,0x10,0x1F,0xF8,0x01,0x00,0x01,0x00,0x01,0x04,0x7F,0xFE,0x00,0x00,

/*��   CCCD7 */
0x02,0x00,0x02,0x00,0x7F,0xFE,0x04,0x40,0x0F,0xE0,0x38,0x18,0xCF,0xEE,0x08,0x04,
0x0F,0xE0,0x08,0x00,0xFF,0xFE,0x04,0x00,0x08,0x20,0x11,0xF0,0x3F,0x18,0x00,0x10,

/*��   CBCBC */
0x10,0x20,0x10,0x20,0x10,0x20,0xFD,0xFE,0x10,0x20,0x14,0x20,0x19,0xFC,0x31,0x08,
0xD0,0x88,0x10,0x90,0x10,0x60,0x10,0x60,0x10,0x90,0x11,0x0E,0x56,0x04,0x20,0x00,

/*��   CCAF5 */
0x01,0x00,0x01,0x20,0x01,0x10,0x01,0x00,0xFF,0xFE,0x01,0x00,0x03,0x80,0x05,0x40,
0x05,0x20,0x09,0x10,0x11,0x18,0x21,0x0E,0xC1,0x04,0x01,0x00,0x01,0x00,0x00,0x00,

/*��   CB7BD */
0x02,0x00,0x01,0x00,0x00,0x80,0xFF,0xFE,0x02,0x00,0x02,0x00,0x03,0xF0,0x02,0x10,
0x04,0x10,0x04,0x10,0x08,0x10,0x08,0x10,0x10,0x10,0x20,0x90,0xC0,0x60,0x00,0x00,

/*��   CB0B8 */
0x02,0x00,0x01,0x00,0x3F,0xFC,0x22,0x08,0x04,0x40,0x7F,0xFC,0x0C,0x80,0x03,0x80,
0x1E,0x60,0x01,0x20,0x7F,0xFE,0x03,0x40,0x0D,0x30,0x71,0x0E,0x01,0x04,0x01,0x00,

/*��   CA1A3 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x30,0x00,0x48,0x00,0x48,0x00,0x30,0x00,0x00,0x00,0x00,0x00,

/*��   CCAC7 */
0x00,0x00,0x0F,0xF0,0x08,0x10,0x0F,0xF0,0x08,0x10,0x0F,0xF0,0x00,0x00,0xFF,0xFE,
0x01,0x00,0x09,0x00,0x09,0xF8,0x09,0x00,0x15,0x00,0x23,0x00,0x40,0xFE,0x00,0x00,

/*��   CBAAB */
0x10,0x20,0x10,0x20,0xFD,0xFE,0x10,0x20,0x7C,0x20,0x44,0xFC,0x7C,0x20,0x44,0x20,
0x7D,0xFE,0x10,0x22,0xFE,0x22,0x10,0x22,0x10,0x2A,0x10,0x24,0x10,0x20,0x10,0x20,

/*��   CB9FA */
0x00,0x00,0x7F,0xFC,0x40,0x04,0x5F,0xF4,0x41,0x04,0x41,0x04,0x41,0x04,0x4F,0xE4,
0x41,0x44,0x41,0x24,0x41,0x24,0x5F,0xF4,0x40,0x04,0x40,0x04,0x7F,0xFC,0x40,0x04,

/*��   CD6D0 */
0x01,0x00,0x01,0x00,0x21,0x08,0x3F,0xFC,0x21,0x08,0x21,0x08,0x21,0x08,0x21,0x08,
0x21,0x08,0x3F,0xF8,0x21,0x08,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,

/*��   CC7F8 */
0x00,0x00,0x7F,0xFC,0x40,0x20,0x40,0x30,0x48,0x20,0x46,0x40,0x41,0x40,0x40,0x80,
0x41,0x40,0x42,0x20,0x44,0x30,0x48,0x18,0x50,0x10,0x7F,0xFC,0x00,0x00,0x00,0x00,

/*��   CD3F2 */
0x20,0x20,0x20,0x28,0x20,0x24,0x27,0xFE,0xF8,0x20,0x20,0x24,0x27,0xA6,0x24,0xA4,
0x24,0xA8,0x27,0xA8,0x24,0x90,0x38,0x32,0xC3,0x4A,0x0C,0x8A,0x03,0x04,0x00,0x00,

/*��   CCADA */
0x20,0x3C,0x27,0xC0,0x20,0x84,0xFA,0x48,0x21,0x50,0x27,0xFE,0x2C,0x04,0x30,0x00,
0x63,0xF8,0xA1,0x10,0x20,0xA0,0x20,0x40,0x20,0xA0,0x23,0x1C,0xAC,0x08,0x40,0x00,

/*Ȩ   CC8A8 */
0x10,0x00,0x10,0x00,0x11,0xFC,0xFE,0x84,0x10,0x88,0x30,0x88,0x38,0x88,0x34,0x48,
0x54,0x50,0x50,0x50,0x90,0x20,0x10,0x20,0x10,0x50,0x11,0x8E,0x16,0x04,0x10,0x00,

/*��   CD7DC */
0x08,0x20,0x04,0x20,0x04,0x40,0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,
0x00,0x00,0x01,0x00,0x08,0x88,0x28,0x84,0x28,0x16,0x68,0x12,0x07,0xF0,0x00,0x00,

/*��   CB4FA */
0x11,0x00,0x19,0x20,0x11,0x10,0x11,0x08,0x21,0xFC,0x3F,0x00,0x50,0x80,0x90,0x80,
0x10,0x80,0x10,0x40,0x10,0x40,0x10,0x24,0x10,0x14,0x10,0x0C,0x10,0x06,0x00,0x00,

/*��   CC0ED */
0x00,0x00,0x03,0xFC,0xFA,0x44,0x22,0x44,0x23,0xFC,0x22,0x44,0xFA,0x44,0x23,0xFC,
0x22,0x44,0x20,0x40,0x23,0xFC,0x38,0x40,0xC0,0x40,0x00,0x40,0x0F,0xFE,0x00,0x00,

/*̨   CCCA8 */
0x01,0x00,0x01,0x80,0x02,0x00,0x04,0x10,0x08,0x08,0x11,0xFC,0x3F,0x08,0x00,0x00,
0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,0x00,0x00,

/*��   CCDE5 */
0x20,0x80,0x10,0x40,0x17,0xFE,0x08,0xA0,0x8A,0xA4,0x54,0xA2,0x53,0xF8,0x10,0x08,
0x23,0xF8,0x22,0x00,0xE3,0xFC,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x14,0x20,0x08,

/*��   CB2C9 */
0x00,0x00,0x01,0xF8,0x7E,0x00,0x00,0x10,0x11,0x10,0x08,0xA0,0x01,0x00,0x7F,0xFE,
0x01,0x80,0x03,0x40,0x05,0x20,0x09,0x18,0x31,0x0E,0xC1,0x04,0x01,0x00,0x01,0x00,

/*��   CB9E2 */
0x01,0x00,0x21,0x10,0x19,0x18,0x0D,0x10,0x09,0x20,0x01,0x04,0x7F,0xFE,0x04,0x40,
0x04,0x40,0x04,0x40,0x04,0x40,0x08,0x42,0x08,0x42,0x10,0x42,0x20,0x3E,0x40,0x00,

/*��   CB4F3 */
0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFE,0x01,0x00,0x02,0x80,
0x02,0x80,0x02,0x40,0x04,0x40,0x04,0x20,0x08,0x10,0x10,0x18,0x20,0x0E,0x40,0x04,

/*½   CC2BD */
0x00,0x40,0xF8,0x40,0x88,0x40,0x97,0xFC,0xA0,0x40,0x90,0x40,0x88,0x40,0x8F,0xFE,
0x88,0x40,0xA8,0x40,0x94,0x44,0x84,0x44,0x84,0x44,0x87,0xFC,0x84,0x04,0x80,0x00,

/*ָ   CD6B8 */
0x11,0x00,0x11,0x38,0x11,0xC0,0x11,0x04,0xFD,0x04,0x11,0xFC,0x14,0x00,0x19,0xFC,
0x31,0x04,0xD1,0x04,0x11,0xFC,0x11,0x04,0x11,0x04,0x11,0x04,0x51,0xFC,0x20,0x00,

/*��   CB6A8 */
0x02,0x00,0x01,0x00,0x3F,0xFE,0x20,0x04,0x40,0x08,0x1F,0xF0,0x01,0x00,0x11,0x00,
0x11,0x00,0x11,0xF0,0x11,0x00,0x29,0x00,0x25,0x00,0x43,0x00,0x81,0xFC,0x00,0x00,

/*��   CC9CC */
0x01,0x00,0x00,0x80,0x7F,0xFC,0x04,0x20,0x02,0x40,0x3F,0xF8,0x22,0x48,0x24,0x28,
0x3F,0xE8,0x24,0x48,0x24,0x48,0x27,0xC8,0x24,0x48,0x24,0x08,0x20,0x28,0x20,0x10,

/*Ϊ   CCEAA */
0x00,0x80,0x10,0x80,0x0C,0x80,0x04,0x84,0x7F,0xFE,0x01,0x04,0x01,0x04,0x01,0x84,
0x01,0x44,0x02,0x24,0x02,0x24,0x04,0x04,0x08,0x44,0x10,0x28,0x20,0x10,0x00,0x00,

/*��   CB9E3 */
0x01,0x00,0x00,0x80,0x3F,0xFE,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,
0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x40,0x00,0x40,0x00,0x80,0x00,0x00,0x00,

/*��   CD3C3 */
0x00,0x00,0x1F,0xFC,0x10,0x84,0x10,0x84,0x10,0x84,0x1F,0xFC,0x10,0x84,0x10,0x84,
0x10,0x84,0x1F,0xFC,0x10,0x84,0x10,0x84,0x20,0x84,0x20,0x84,0x40,0x94,0x80,0x88,

/*��   CBBA7 */
0x01,0x00,0x00,0xC0,0x00,0x40,0x1F,0xFC,0x10,0x04,0x10,0x04,0x10,0x04,0x1F,0xFC,
0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x20,0x00,0x20,0x00,0x40,0x00,0x80,0x00,

/*��   CC8D5 */
0x00,0x00,0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,0x00,0x00,0x00,0x00,

/*��   CB1BE */
0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFE,0x03,0x80,0x03,0x40,0x05,0x40,0x05,0x20,
0x09,0x10,0x11,0x18,0x2F,0xEE,0xC1,0x04,0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x00,

/*��   CC6C1 */
0x3F,0xFC,0x20,0x04,0x20,0x04,0x3F,0xFC,0x24,0x10,0x22,0x20,0x2F,0xFC,0x22,0x20,
0x22,0x20,0x3F,0xFE,0x22,0x20,0x22,0x20,0x44,0x20,0x44,0x20,0x88,0x20,0x10,0x20,

/*��   CBACD */
0x00,0x00,0x07,0x00,0x78,0x00,0x08,0x7C,0x08,0x44,0x7F,0x44,0x08,0x44,0x18,0x44,
0x1C,0x44,0x2A,0x44,0x2B,0x44,0x4A,0x44,0x88,0x7C,0x08,0x44,0x08,0x00,0x08,0x00,

/*Ʒ   CC6B7 */
0x00,0x00,0x0F,0xF0,0x08,0x10,0x08,0x10,0x08,0x10,0x0F,0xF0,0x08,0x10,0x00,0x00,
0x7E,0xFC,0x42,0x84,0x42,0x84,0x42,0x84,0x42,0x84,0x7E,0xFC,0x42,0x84,0x00,0x00,

/*��   CD2D4 */
0x00,0x10,0x24,0x10,0x22,0x10,0x23,0x10,0x22,0x10,0x20,0x10,0x20,0x10,0x21,0x10,
0x22,0x10,0x2C,0x30,0x38,0x30,0x70,0x68,0x20,0xC4,0x01,0x07,0x06,0x02,0x00,0x00,

/*��   CBCB0 */
0x00,0x00,0x3F,0xE0,0x04,0x20,0x04,0x20,0x04,0x40,0x04,0x40,0x04,0xF8,0x0A,0x50,
0x0A,0x10,0x09,0x20,0x11,0x20,0x10,0xC0,0x21,0x20,0x42,0x18,0x8C,0x0E,0x30,0x04,

/*��   CB8F7 */
0x04,0x00,0x04,0x00,0x07,0xF0,0x0C,0x20,0x12,0x20,0x62,0x40,0x01,0x80,0x06,0x60,
0x18,0x1E,0xEF,0xF4,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x0F,0xF0,0x00,0x00,

/*��   CD6D6 */
0x06,0x20,0x78,0x20,0x08,0x20,0x08,0x20,0x7D,0xFC,0x09,0x24,0x1D,0x24,0x1B,0x24,
0x29,0xFC,0x29,0x24,0x48,0x20,0x88,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0x08,0x20,

/*��   CD6DC */
0x00,0x00,0x1F,0xFC,0x10,0x84,0x13,0xE4,0x10,0x84,0x10,0x84,0x17,0xF4,0x10,0x04,
0x13,0xE4,0x12,0x24,0x12,0x24,0x13,0xE4,0x22,0x24,0x20,0x04,0x40,0x14,0x80,0x08,

/*��   CB1DF */
0x40,0x80,0x20,0x80,0x30,0x80,0x20,0x80,0x07,0xF8,0x00,0x88,0xF0,0x88,0x10,0x88,
0x11,0x08,0x11,0x08,0x12,0x08,0x14,0x70,0x10,0x20,0x28,0x00,0x47,0xFE,0x00,0x00,

/*��   CC5E4 */
0x00,0x00,0xFE,0xFC,0x28,0x04,0x28,0x04,0xFE,0x04,0xAA,0x04,0xAA,0xFC,0xAA,0x80,
0xC6,0x80,0x82,0x80,0xFE,0x80,0x82,0x82,0x82,0x82,0xFE,0x82,0x82,0x7E,0x00,0x00,

/*��   CBCFE */
0x10,0x40,0x1A,0x40,0x13,0x40,0x32,0x40,0x23,0xFC,0x64,0x40,0xA4,0x40,0x28,0x40,
0x2F,0xFE,0x20,0x40,0x20,0x40,0x20,0x40,0x20,0x40,0x20,0x40,0x20,0x40,0x20,0x40,

/*��   CA3A8 */
0x00,0x0C,0x00,0x10,0x00,0x20,0x00,0x40,0x00,0x40,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x40,0x00,0x40,0x00,0x20,0x00,0x10,0x00,0x0C,

/*��   CC4E6 */
0x02,0x10,0x41,0x10,0x21,0x20,0x27,0xFC,0x00,0x40,0x00,0x40,0xE2,0x48,0x22,0x48,
0x23,0xF8,0x20,0x80,0x20,0x80,0x21,0x00,0x22,0x00,0x50,0x00,0x8F,0xFE,0x00,0x00,

/*��   CB1E4 */
0x02,0x00,0x01,0x80,0x7F,0xFE,0x02,0x40,0x12,0x50,0x1A,0x4C,0x22,0x46,0x42,0x44,
0x9F,0xF0,0x04,0x20,0x04,0x20,0x02,0x40,0x01,0x80,0x06,0x60,0x18,0x1E,0xE0,0x08,

/*��   CC6F7 */
0x3E,0x7C,0x22,0x44,0x22,0x44,0x3E,0x7C,0x01,0x10,0x01,0x08,0xFF,0xFC,0x06,0xC0,
0x18,0x30,0xE0,0x0E,0x3E,0xFC,0x22,0x88,0x22,0x88,0x22,0x88,0x3E,0xF8,0x00,0x00,

/*��   CB9A4 */
0x00,0x00,0x3F,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFE,0x00,0x00,0x00,0x00,

/*��   CBFD8 */
0x10,0x00,0x10,0x20,0x10,0x10,0xFD,0xFE,0x11,0x04,0x10,0x50,0x14,0x8C,0x19,0x04,
0x30,0x00,0xD1,0xFC,0x10,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x53,0xFE,0x20,0x00,

/*��   CB0E5 */
0x10,0x1C,0x11,0xE0,0x11,0x00,0x11,0x00,0xFD,0x00,0x11,0xFC,0x39,0x84,0x35,0x48,
0x55,0x48,0x52,0x30,0x92,0x10,0x12,0x30,0x14,0x48,0x10,0x8E,0x11,0x04,0x00,0x00,

/*��   CC1AC */
0x40,0x80,0x20,0x80,0x37,0xFC,0x21,0x00,0x01,0x40,0x02,0x40,0xF7,0xF8,0x12,0x40,
0x10,0x40,0x1F,0xFE,0x10,0x40,0x10,0x40,0x10,0x40,0x28,0x00,0x47,0xFE,0x00,0x00,

/*��   CBDD3 */
0x10,0x40,0x10,0x20,0x13,0xFC,0xFD,0x08,0x10,0x90,0x17,0xFE,0x14,0x00,0x18,0x80,
0x30,0x80,0xDF,0xFE,0x11,0x10,0x13,0x10,0x10,0xE0,0x10,0x50,0x51,0x8C,0x26,0x04,

/*��   CCFDF */
0x10,0x40,0x18,0x50,0x10,0x4C,0x20,0x48,0x23,0xFC,0x48,0x40,0xF8,0x40,0x13,0xFE,
0x20,0x40,0x7C,0x48,0x00,0x30,0x00,0x22,0x1C,0xD2,0xE3,0x0A,0x00,0x06,0x00,0x02,

/*��   CC0C2 */
0x00,0x90,0x22,0x90,0x32,0x9E,0x22,0xA0,0x4A,0xC8,0xF0,0x84,0x13,0xF8,0x22,0x08,
0x42,0x48,0xFA,0x48,0x02,0x48,0x00,0xA0,0x38,0xA2,0xE1,0x22,0x02,0x1E,0x04,0x00,

/*��   CB4A5 */
0x20,0x10,0x3F,0x10,0x21,0x10,0x42,0x10,0x7F,0x7C,0xC9,0x54,0x7F,0x54,0x49,0x54,
0x49,0x54,0x7F,0x7C,0x49,0x10,0x49,0x14,0x49,0x12,0x49,0x1E,0x85,0xF2,0x02,0x00,

/*��   CC3FE */
0x11,0x10,0x11,0x10,0x17,0xFE,0xF9,0x10,0x13,0xF8,0x12,0x08,0x1B,0xF8,0x32,0x08,
0xD3,0xF8,0x10,0x40,0x17,0xFE,0x10,0x40,0x10,0xA0,0x10,0x98,0x51,0x0E,0x26,0x04,

/*ת   CD7AA */
0x10,0x20,0x10,0x20,0x20,0x20,0xFE,0xFC,0x20,0x40,0x50,0x40,0x91,0xFE,0xFE,0x40,
0x10,0x80,0x11,0xFC,0x3C,0x08,0xD0,0x88,0x10,0x50,0x10,0x20,0x10,0x10,0x10,0x10,

/*��   CC7FD */
0x00,0x00,0xF9,0xFE,0x09,0x00,0x49,0x04,0x49,0x84,0x49,0x48,0x49,0x28,0x7D,0x10,
0x05,0x18,0x05,0x28,0x35,0x24,0xC5,0x44,0x05,0x84,0x29,0x00,0x11,0xFE,0x00,0x00,

/*��   CB6AF */
0x00,0x20,0x00,0x20,0x7E,0x20,0x00,0x20,0x00,0xFC,0xFF,0x24,0x10,0x24,0x10,0x24,
0x24,0x24,0x22,0x24,0x4F,0x44,0xFA,0x44,0x40,0x84,0x01,0x14,0x02,0x08,0x00,0x00,

/*��   CBFA8 */
0x01,0x00,0x01,0x00,0x01,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x7F,0xFE,0x01,0x00,
0x01,0x00,0x01,0x40,0x01,0x30,0x01,0x18,0x01,0x0C,0x01,0x08,0x01,0x00,0x01,0x00,

/*��   CB5C8 */
0x20,0x80,0x3E,0xFC,0x28,0xA0,0x45,0x10,0x85,0x10,0x3F,0xF8,0x01,0x00,0xFF,0xFE,
0x00,0x20,0x00,0x20,0x7F,0xFC,0x04,0x20,0x02,0x20,0x02,0x20,0x00,0xA0,0x00,0x40,

/*��   CA3A9 */
0x60,0x00,0x10,0x00,0x08,0x00,0x04,0x00,0x04,0x00,0x02,0x00,0x02,0x00,0x02,0x00,
0x02,0x00,0x02,0x00,0x02,0x00,0x04,0x00,0x04,0x00,0x08,0x00,0x10,0x00,0x60,0x00

};

unsigned char const hz1624[] = {
0x00,0x00,0x01,0x00,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x84,
0x3F,0xF8,0x01,0x80,0x02,0xC0,0x02,0xC0,0x02,0xA0,0x04,0xA0,0x04,0x90,
0x08,0x90,0x08,0x88,0x10,0x8C,0x2F,0xF6,0x40,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x01,0x00,/*"��",0*/
0x00,0x00,0x00,0x00,0x10,0x20,0x10,0x20,0x10,0x20,0x11,0x20,0x11,0x20,
0x11,0x2C,0x11,0x34,0x3D,0x64,0x11,0xA4,0x17,0x24,0x11,0x24,0x11,0x24,
0x11,0x24,0x11,0x3C,0x11,0x2A,0x15,0x22,0x19,0x02,0x61,0x02,0x41,0x02,
0x01,0xFE,0x00,0x00,0x00,0x00,/*"��",1*/
0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x08,0x13,0xF8,0x10,0x00,0x10,0x00,
0x00,0x04,0x03,0x5C,0x00,0xA0,0x70,0xA0,0x11,0x20,0x11,0x20,0x11,0x20,
0x11,0x20,0x11,0x24,0x12,0x24,0x12,0x36,0x14,0x1C,0x68,0x00,0x46,0x00,
0x43,0xFC,0x00,0x00,0x00,0x00,/*"Զ",2*/
0x00,0x00,0x00,0x00,0x04,0x00,0x3C,0xFE,0x48,0x84,0x08,0x84,0x08,0x84,
0x08,0x84,0x2E,0xFC,0x18,0x84,0x18,0x00,0x18,0x00,0x1D,0xFC,0x1A,0x20,
0x28,0x20,0x28,0x20,0x29,0xFC,0x48,0x20,0x48,0x20,0x08,0x20,0x08,0x22,
0x0B,0xFE,0x08,0x00,0x00,0x00,/*"��",3*/
0x00,0x00,0x00,0x80,0x08,0x40,0x10,0x40,0x13,0xFC,0x10,0x00,0x10,0x08,
0x21,0xF8,0x31,0x08,0x31,0xF8,0x51,0x08,0x54,0x00,0x17,0xFE,0x14,0x04,
0x1C,0x08,0x13,0xFC,0x10,0x40,0x10,0x40,0x10,0x40,0x10,0x40,0x10,0x40,
0x11,0xC0,0x10,0x40,0x00,0x00,/*"ͣ",4*/
0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x08,0x80,0x08,0xFC,0x08,0x80,0x08,0x80,0x08,0x80,0x08,0x80,
0x08,0x80,0x08,0x80,0x08,0x80,0x08,0x80,0x08,0x80,0x08,0x80,0x08,0x86,
0x77,0x78,0x00,0x00,0x00,0x00,/*"ֹ",5*/
0x00,0x00,0x08,0x20,0x08,0x10,0x08,0x20,0x08,0x24,0x7F,0xFE,0x0C,0x30,
0x1A,0x68,0x1A,0x68,0x28,0xA4,0x28,0xA6,0x49,0x20,0x00,0x08,0x1F,0xF8,
0x00,0x00,0x7F,0xFE,0x00,0x80,0x04,0xA0,0x0C,0x90,0x08,0x88,0x10,0x8C,
0x23,0x84,0x01,0x00,0x00,0x00,/*"��",6*/
0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x08,0x80,0x08,0xFC,0x08,0x80,0x08,0x80,0x08,0x80,0x08,0x80,
0x08,0x80,0x08,0x80,0x08,0x80,0x08,0x80,0x08,0x80,0x08,0x80,0x08,0x86,
0x77,0x78,0x00,0x00,0x00,0x00,/*"ֹ",7*/
0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0xDC,0x04,0x20,0x04,0x20,0x04,0x20,
0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x26,0x7F,0xFE,0x04,0x20,0x04,0x20,
0x04,0x20,0x04,0x20,0x04,0x20,0x08,0x20,0x08,0x20,0x10,0x20,0x10,0x20,
0x20,0x20,0x40,0x20,0x00,0x00,/*"��",8*/
0x00,0x00,0x00,0x00,0x04,0x20,0x04,0x20,0x02,0x20,0x02,0x40,0x02,0x44,
0x3F,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x06,0x7F,0xFE,
0x01,0x40,0x01,0x40,0x02,0x40,0x02,0x20,0x04,0x20,0x04,0x10,0x08,0x18,
0x10,0x0E,0x20,0x04,0x00,0x00,/*"��",9*/
0x00,0x00,0x00,0x00,0x10,0x00,0x0B,0xFC,0x08,0x04,0x28,0x84,0x22,0xA4,
0x22,0x94,0x24,0x94,0x24,0x94,0x24,0xEC,0x2F,0x84,0x2C,0x94,0x34,0xA4,
0x24,0x64,0x24,0x44,0x24,0xCC,0x25,0x2C,0x26,0x34,0x24,0x0C,0x20,0x04,
0x20,0x1C,0x20,0x0C,0x00,0x00,/*"��",10*/
};

unsigned char const hz1616[] = {
    0x40,0x00,0x27,0xFE,0x24,0x04,0x01,0x20,0x81,0x18,0x56,0x08,0x50,0x40,0x10,0x40,
    0x27,0xFC,0x20,0x40,0xC0,0xE0,0x41,0x58,0x46,0x4E,0x58,0x44,0x40,0x40,0x40,0x40,
};

unsigned char const hz1414[] = {
    0x20,0x00,0x20,0x00,0xFF,0x07,0x20,0x00,0x70,0x00,0xA8,0x00,0xA8,0x00,
0x24,0x01,0x22,0x02,0xFD,0x05,0x20,0x00,0x20,0x00,/*"��",0*/
0x84,0x00,0x84,0x00,0xA4,0x06,0xA4,0x05,0xEF,0x04,0xB4,0x04,0xA4,0x04,
0xA4,0x06,0xA4,0x00,0x2C,0x04,0x23,0x04,0xC0,0x07,/*"��",1*/

};

unsigned char const hz1212[] = {
    0x11,0x00,0x1F,0xE0,0x20,0x00,0x27,0xC0,0x64,0x40,0xA7,0xC0,0x20,0x00,
    0x2F,0xE0,0x28,0x20,0x27,0xC0,0x21,0x00,0x23,0x00,/*"ͣ",0*/
    0x02,0x00,0x02,0x00,0x02,0x00,0x22,0x00,0x23,0xC0,0x22,0x00,0x22,0x00,
    0x22,0x00,0x22,0x00,0x22,0x00,0x22,0x00,0xFF,0xE0,/*"ֹ",1*/
};