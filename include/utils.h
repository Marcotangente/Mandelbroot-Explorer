#ifndef __UTILS__
#define __UTILS__

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

typedef enum{
    SUCCESS,
    ERR_NULL_PTR,
    ERR_ALLOCATION_FAIL,
    ERR_OUT_OF_BOUNDS,
    ERR_INVALID_ARG,
}ErrorCode;

#endif
