#pragma once

#include "superblock.h"
#include "block.h"
#include "../device_io.h"
#include "../fs_def.h"

typedef enum {
    YIREN_SUCCESS,
    Y1REN_FAIL
} yiren_errcode_t;

typedef struct {
    superblock_t sb;
} yiren_filesystem_t;

yiren_filesystem_t* yiren_filesystem_new(device_handle_t device);
bool yiren_filesystem_init(yiren_filesystem_t* fs, device_handle_t device);

fs_size_t yiren_filesystem_used_size(yiren_filesystem_t* fs);
fs_size_t yiren_filesystem_total_size(yiren_filesystem_t* fs);

// 将device设备格式化
bool yiren_format(device_handle_t device, int sectors_per_block);