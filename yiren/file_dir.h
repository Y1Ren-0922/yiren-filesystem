#pragma once

#include "base_file.h"
#include "filesystem.h"

#include "../fs_def.h"

typedef struct {
    base_file_t base_file;
}yiren_file_t;


yiren_file_t* yiren_open(device_handle_t device, yiren_filesystem_t* fs, const char* path);
void yiren_close(yiren_file_t* file);

int yiren_read(yiren_file_t* file, char* buf, int count);
int yiren_write(yiren_file_t* file, const char* buf, int count);
bool yiren_ftruncate(yiren_file_t* file, fs_off_t size);
fs_off_t yiren_lseek(yiren_file_t* file, fs_off_t off, int where);

bool yiren_mkdir(device_handle_t device, yiren_filesystem_t* fs, const char* path);
bool yiren_rmdir(device_handle_t device, yiren_filesystem_t* fs, const char* path);

bool yiren_mv(device_handle_t device, yiren_filesystem_t* fs, const char* src_path, const char* new_path);
bool yiren_link(device_handle_t device, yiren_filesystem_t* fs, const char* src_path, const char* new_path);
bool yiren_unlink(device_handle_t device, yiren_filesystem_t* fs, const char* path);

bool yiren_symlink(device_handle_t device, yiren_filesystem_t* fs, const char* src_path, const char* new_path);
bool yiren_readlink(device_handle_t device, yiren_filesystem_t* fs, const char *path, char *buf, size_t size);

bool yiren_stat(device_handle_t device, yiren_filesystem_t* fs, const char *path, struct fs_stat *buf);


typedef struct {
    base_file_t base_file;
}yiren_dir_t;

yiren_dir_t* yiren_opendir(device_handle_t device, yiren_filesystem_t* fs, const char *path);
bool yiren_readdir(yiren_dir_t* dir, char* name);
bool yiren_closedir(yiren_dir_t* dir);