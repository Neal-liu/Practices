#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define PNG_DEBUG 3
#include<png.h>

/* some file local variable to save tmp image */
static int width = 0;
static int height = 0;
static int stride = 0;

static png_bytep *row_pointers;
static png_byte color_type;
static png_byte bit_depth;

#define TABLE_SIZE 256
unsigned char mul_299[TABLE_SIZE];
unsigned char mul_587[TABLE_SIZE];
unsigned char mul_114[TABLE_SIZE];


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
			bw = (uint32_t)(mul_299[r] + mul_587[g] + mul_114[b]);
			bitmap[col + row * stride / 4] = (a << 24) + (bw << 16) + (bw << 8) + (bw);
		}
	}
}

void table(){

	for(int i = 0 ; i < TABLE_SIZE ; i++){
		mul_299[i] = i*0.299;
		mul_587[i] = i*0.587;
		mul_114[i] = i*0.114;
		
	}
}

void read_image(const char* filename)
{
	FILE *fp = fopen(filename, "rb");
	if (!fp) {
		perror("open file");
		return;
	}

	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(!png) abort();

	png_infop info = png_create_info_struct(png);
	if(!info) abort();

	if(setjmp(png_jmpbuf(png))) abort();

	png_init_io(png, fp);

	png_read_info(png, info);

	width      = png_get_image_width(png, info);
	height     = png_get_image_height(png, info);
	color_type = png_get_color_type(png, info);
	bit_depth  = png_get_bit_depth(png, info);

	// Read any color_type into 8bit depth, RGBA format.
	// See http://www.libpng.org/pub/png/libpng-manual.txt

	if(bit_depth == 16)
		png_set_strip_16(png);

	if(color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png);

	// PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
	if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
		png_set_expand_gray_1_2_4_to_8(png);

	if(png_get_valid(png, info, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha(png);

	// These color_type don't have an alpha channel then fill it with 0xff.
	if(color_type == PNG_COLOR_TYPE_RGB ||
			color_type == PNG_COLOR_TYPE_GRAY ||
			color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

	if(color_type == PNG_COLOR_TYPE_GRAY ||
			color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png);

	png_read_update_info(png, info);

	stride = png_get_rowbytes(png, info);
	png_bytep pixels = (png_bytep) malloc(height * stride);

	row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
	for(int y = 0; y < height; y++) {
		//                row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
		row_pointers[y] = pixels + stride * y;
	}

	png_read_image(png, row_pointers);

	fclose(fp);
}

void write_img(const char *filename)
{
	FILE *fp = fopen(filename, "wb");
	if (!fp) {
		perror("write file");
		exit(-1);
	}

	png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png) abort();

	png_infop info = png_create_info_struct(png);
	if (!info) abort();

	if (setjmp(png_jmpbuf(png))) abort();

	png_init_io(png, fp);

	// Output is 8bit depth, RGBA format.
	png_set_IHDR (
			png,
			info,
			width, height,
			8,
			PNG_COLOR_TYPE_RGBA,
			PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_DEFAULT,
			PNG_FILTER_TYPE_DEFAULT);
	png_write_info(png, info);


	png_write_image(png, row_pointers);

	png_write_end(png, NULL);

	// FIXME:
	// malloc: *** error for object 0x1066fe960: pointer being freed was not allocated
	// for(int y = 0; y < height; y++) {
	//         free(row_pointers[y]);
	// }
	free(row_pointers);

	fclose(fp);
}

void process_img()
{
        rgba_to_bw((uint32_t *) *row_pointers, width, height, stride);

}

int NanoTime(void)
{
	struct timespec t;
	t.tv_sec = t.tv_nsec = 0;
	clock_gettime(CLOCK_MONOTONIC, &t);
//	return t.tv_nsec;
	return t.tv_sec * 1000000000LL + t.tv_nsec;
}

int main(int argc, char *argv[])
{
	int starttime = 0, endtime = 0;

	read_image("beauty.png");
	table();
	starttime = NanoTime();
	process_img();
	endtime = NanoTime();
	printf("success !!\n Process img time is %d nanoseconds\n", (endtime-starttime));

	write_img(OUTPUT);

	return 0;
}
