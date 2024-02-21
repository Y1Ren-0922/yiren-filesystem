#pragma once

/**
抽象磁盘。把一个大文件虚拟成一个磁盘，赋予一个磁盘号，并以扇区为单位进行读写。
*/

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

// 扇区大小
#define BYTES_PER_SECTOR 512

#define DEVICE_IO_ERROR -1

#define DEVICE_IO_SUCCESS(handle) (handle >= 0)

typedef int device_handle_t;
typedef uint64_t sector_no_t;

struct _device_s {
    char* path;
    FILE* fp;
    sector_no_t section_count;
};

// 将外部系统的path文件模拟成系统的一个磁盘，返回其句柄，错误则返回-1
device_handle_t device_add(const char *path);

// 设备卸载
void device_del(device_handle_t handle);

// 从section_no扇区开始，读取count个扇区的内容到buf中。返回读取的扇区，错误返回-1
sector_no_t device_read(device_handle_t handle, sector_no_t secotr_no, sector_no_t count, char *buf);

// 将buf中内容写入到从section_no扇区开始，count个扇区中。返回写入的扇区数。错误返回-1
sector_no_t device_write(device_handle_t handle, sector_no_t secotr_no, sector_no_t count, const char *buf);

sector_no_t device_section_count(device_handle_t handle);