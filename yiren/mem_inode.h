#pragma once

#include "inode.h"

#define MAX_MEM_INODE_COUNT 1024    

typedef struct {
    device_handle_t device;
    inode_no_t inode_no;
    inode_t inode;
    int ref_count;
} mem_inode_t;

bool mem_inode_get(dev_inode_ctrl_t* dev_inode_ctrl, inode_no_t inode_no, mem_inode_t** p_result);
bool mem_inode_put(dev_inode_ctrl_t* dev_inode_ctrl, mem_inode_t* mem_inode);