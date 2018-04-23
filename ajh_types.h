//TODO(Armin): make platform independet
typedef float               f32;
typedef double              f64;
typedef unsigned char        u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
typedef char                 i8;
typedef short               i16;
typedef int                 i32;
typedef long long           i64;
typedef u64            ajh_size;
typedef u32            ajh_bool;
typedef i8*             ajh_chp;


#define def_struct(name,fields) typedef struct ajh_##name { fields } ajh_##name
#define def_union(name,fields)  typedef union  ajh_##name { fields } ajh_##name

#define intern static
#define true  1
#define false 0

