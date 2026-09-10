#ifndef STATIC_HPP
#define STATIC_HPP

#include <cstdint>
#include <string>

typedef uint32_t u32;
typedef struct Thread{
    //threads id
    u32 thread_id;
    //speed
    float MHz;
    //integer values
    u32 load;
    u32 temperature;
    //point to the next thread
    Thread *next;
}Thread;
typedef struct Cpu{
    //strings
    std::string name;
    std::string vendor;
    //fpu check
    bool fpu;
    //integer values
    u32 thread_count;
    u32 core_count;
    u32 load;
    u32 temperature;
}Cpu;

typedef struct Partitions{
    //strings
    std::string name;
    std::string type;
    std::string mount_point;
    std::string uuid;
    //size in bytes
    u32 size;
    u32 occupied_size;
    //point to the next partition
    Partitions *next;
}Partitions;
typedef struct Disks{
    Partitions partition;
    Disks *next;
    uint32_t id;
}Disks;

#endif