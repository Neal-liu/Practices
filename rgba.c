#include<stdio.h>

int main(void)
{

	return 0;
}

void rgba_to_bw(uint32_t *bitmap, int width, int height, long stride) {
	int row, col;
	uint32_t pixel, r, g, b, a, bw;
	for (row = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			pixel = bitmap[col + row * stride / 4];
			a = (pixel >> 24) & 0xff;
			r = (pixel >> 16) & 0xff;
			g = (pixel >> 8) & 0xff;
			b = pixel & 0xff;
			bw = (uint32_t) (r * 0.299 + g * 0.587 + b * 0.114);
			bitmap[col + row * stride / 4] = (a << 24) + (bw << 16) + (bw << 8) + (bw);
		}
	}
}

void bitmap_translate(uint32_t *bitmap, uint32_t *mul_299, uint32_t *mul_587, uint32_t *mul_144){
	for (row = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			mul_299[col + row * stride / 4] = bitmap[col + row * stride / 4]*0.299;
			mul_587[col + row * stride / 4] = bitmap[col + row * stride / 4]*0.587;
			mul_144[col + row * stride / 4] = bitmap[col + row * stride / 4]*0.114;
		}
	}
}
