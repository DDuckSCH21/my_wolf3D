#import <AppKit/NSScreen.h>

void	mlx_get_screen_size(int *width, int *hight)
{
	NSRect disp = [[NSScreen mainScreen] frame];
	*hight = (int)disp.size.height;
	*width = (int)disp.size.width;
}