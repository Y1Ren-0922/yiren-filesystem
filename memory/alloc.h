#pragma once

#include <stddef.h>

/**
 * 提供动态内存管理功能
 * 
*/

#define FT_NEW(type_, size) ((type_ *)ft_malloc0(sizeof(type_) * size))

void* ft_malloc(size_t size);
void* ft_malloc0(size_t size);
void* ft_realloc(void* p, size_t size);
void ft_free(void* p);