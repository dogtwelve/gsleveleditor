#include "stdafx.h"
using namespace irr;
using namespace irr::core;

/*
** Lua binding: quaternion
** Generated automatically by tolua++-1.0.92 on 04/20/13 17:01:27.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
int  tolua_quaternion_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_f32 (lua_State* tolua_S)
{
 f32* self = (f32*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_matrix4 (lua_State* tolua_S)
{
 matrix4* self = (matrix4*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_irr__core__quaternion (lua_State* tolua_S)
{
 irr::core::quaternion* self = (irr::core::quaternion*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"vector3d<f32>");
 tolua_usertype(tolua_S,"f32");
 tolua_usertype(tolua_S,"matrix4");
 tolua_usertype(tolua_S,"irr::core::quaternion");
}

/* method: new of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_new00
static int tolua_quaternion_irr_core_quaternion_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::quaternion* tolua_ret = (irr::core::quaternion*)  new irr::core::quaternion();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::quaternion");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_new00_local
static int tolua_quaternion_irr_core_quaternion_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::quaternion* tolua_ret = (irr::core::quaternion*)  new irr::core::quaternion();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"irr::core::quaternion");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_new01
static int tolua_quaternion_irr_core_quaternion_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"f32",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  f32 X = *((f32*)  tolua_tousertype(tolua_S,2,0));
  f32 Y = *((f32*)  tolua_tousertype(tolua_S,3,0));
  f32 Z = *((f32*)  tolua_tousertype(tolua_S,4,0));
  f32 W = *((f32*)  tolua_tousertype(tolua_S,5,0));
  {
   irr::core::quaternion* tolua_ret = (irr::core::quaternion*)  new irr::core::quaternion(X,Y,Z,W);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_quaternion_irr_core_quaternion_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_new01_local
static int tolua_quaternion_irr_core_quaternion_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"f32",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  f32 X = *((f32*)  tolua_tousertype(tolua_S,2,0));
  f32 Y = *((f32*)  tolua_tousertype(tolua_S,3,0));
  f32 Z = *((f32*)  tolua_tousertype(tolua_S,4,0));
  f32 W = *((f32*)  tolua_tousertype(tolua_S,5,0));
  {
   irr::core::quaternion* tolua_ret = (irr::core::quaternion*)  new irr::core::quaternion(X,Y,Z,W);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"irr::core::quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_quaternion_irr_core_quaternion_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_new02
static int tolua_quaternion_irr_core_quaternion_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"f32",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  f32 x = *((f32*)  tolua_tousertype(tolua_S,2,0));
  f32 y = *((f32*)  tolua_tousertype(tolua_S,3,0));
  f32 z = *((f32*)  tolua_tousertype(tolua_S,4,0));
  {
   irr::core::quaternion* tolua_ret = (irr::core::quaternion*)  new irr::core::quaternion(x,y,z);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_quaternion_irr_core_quaternion_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_new02_local
static int tolua_quaternion_irr_core_quaternion_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"f32",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  f32 x = *((f32*)  tolua_tousertype(tolua_S,2,0));
  f32 y = *((f32*)  tolua_tousertype(tolua_S,3,0));
  f32 z = *((f32*)  tolua_tousertype(tolua_S,4,0));
  {
   irr::core::quaternion* tolua_ret = (irr::core::quaternion*)  new irr::core::quaternion(x,y,z);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"irr::core::quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_quaternion_irr_core_quaternion_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_new03
static int tolua_quaternion_irr_core_quaternion_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  matrix4* mat = ((matrix4*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::quaternion* tolua_ret = (irr::core::quaternion*)  new irr::core::quaternion(*mat);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_quaternion_irr_core_quaternion_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_new03_local
static int tolua_quaternion_irr_core_quaternion_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  matrix4* mat = ((matrix4*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::quaternion* tolua_ret = (irr::core::quaternion*)  new irr::core::quaternion(*mat);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"irr::core::quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_quaternion_irr_core_quaternion_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion__eq00
static int tolua_quaternion_irr_core_quaternion__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
  irr::core::quaternion* other = ((irr::core::quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion__add00
static int tolua_quaternion_irr_core_quaternion__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
  irr::core::quaternion* other = ((irr::core::quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'",NULL);
#endif
  {
   irr::core::quaternion tolua_ret = (irr::core::quaternion)  self->operator+(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = new irr::core::quaternion(tolua_ret);
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::quaternion");
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::quaternion));
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::quaternion");
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion__mul00
static int tolua_quaternion_irr_core_quaternion__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
  irr::core::quaternion* other = ((irr::core::quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'",NULL);
#endif
  {
   irr::core::quaternion tolua_ret = (irr::core::quaternion)  self->operator*(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = new irr::core::quaternion(tolua_ret);
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::quaternion");
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::quaternion));
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::quaternion");
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion__mul01
static int tolua_quaternion_irr_core_quaternion__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"f32",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
  f32 s = *((f32*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'",NULL);
#endif
  {
   irr::core::quaternion tolua_ret = (irr::core::quaternion)  self->operator*(s);
   {
#ifdef __cplusplus
    void* tolua_obj = new irr::core::quaternion(tolua_ret);
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::quaternion");
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::quaternion));
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::quaternion");
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_quaternion_irr_core_quaternion__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: dotProduct of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_dotProduct00
static int tolua_quaternion_irr_core_quaternion_dotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
  irr::core::quaternion* other = ((irr::core::quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dotProduct'",NULL);
#endif
  {
   f32 tolua_ret = (f32)  self->dotProduct(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = new f32(tolua_ret);
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"f32");
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(f32));
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"f32");
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_set00
static int tolua_quaternion_irr_core_quaternion_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"f32",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
  f32 x = *((f32*)  tolua_tousertype(tolua_S,2,0));
  f32 y = *((f32*)  tolua_tousertype(tolua_S,3,0));
  f32 z = *((f32*)  tolua_tousertype(tolua_S,4,0));
  f32 w = *((f32*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
  {
   self->set(x,y,z,w);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_set01
static int tolua_quaternion_irr_core_quaternion_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"f32",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
  f32 x = *((f32*)  tolua_tousertype(tolua_S,2,0));
  f32 y = *((f32*)  tolua_tousertype(tolua_S,3,0));
  f32 z = *((f32*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
  {
   self->set(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_quaternion_irr_core_quaternion_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_normalize00
static int tolua_quaternion_irr_core_quaternion_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'",NULL);
#endif
  {
   irr::core::quaternion& tolua_ret = (irr::core::quaternion&)  self->normalize();
   tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::quaternion");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMatrix of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_getMatrix00
static int tolua_quaternion_irr_core_quaternion_getMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMatrix'",NULL);
#endif
  {
   matrix4 tolua_ret = (matrix4)  self->getMatrix();
   {
#ifdef __cplusplus
    void* tolua_obj = new matrix4(tolua_ret);
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"matrix4");
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(matrix4));
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"matrix4");
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeInverse of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_makeInverse00
static int tolua_quaternion_irr_core_quaternion_makeInverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeInverse'",NULL);
#endif
  {
   self->makeInverse();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeInverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: slerp of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_slerp00
static int tolua_quaternion_irr_core_quaternion_slerp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"f32",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
  irr::core::quaternion q1 = *((irr::core::quaternion*)  tolua_tousertype(tolua_S,2,0));
  irr::core::quaternion q2 = *((irr::core::quaternion*)  tolua_tousertype(tolua_S,3,0));
  f32 time = *((f32*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'slerp'",NULL);
#endif
  {
   irr::core::quaternion tolua_ret = (irr::core::quaternion)  self->slerp(q1,q2,time);
   {
#ifdef __cplusplus
    void* tolua_obj = new irr::core::quaternion(tolua_ret);
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::quaternion");
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::quaternion));
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::quaternion");
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'slerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromAngleAxis of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_fromAngleAxis00
static int tolua_quaternion_irr_core_quaternion_fromAngleAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"f32",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"vector3d<f32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
  f32 angle = *((f32*)  tolua_tousertype(tolua_S,2,0));
  vector3d<f32>* axis = ((vector3d<f32>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromAngleAxis'",NULL);
#endif
  {
   self->fromAngleAxis(angle,*axis);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromAngleAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toEuler of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_quaternion_irr_core_quaternion_toEuler00
static int tolua_quaternion_irr_core_quaternion_toEuler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"vector3d<f32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
  vector3d<f32>* euler = ((vector3d<f32>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toEuler'",NULL);
#endif
  {
   self->toEuler(*euler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toEuler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: X of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__quaternion_X
static int tolua_get_irr__core__quaternion_X(lua_State* tolua_S)
{
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->X,"f32");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: X of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__quaternion_X
static int tolua_set_irr__core__quaternion_X(lua_State* tolua_S)
{
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
  if (!tolua_isusertype(tolua_S,2,"f32",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->X = *((f32*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Y of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__quaternion_Y
static int tolua_get_irr__core__quaternion_Y(lua_State* tolua_S)
{
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->Y,"f32");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Y of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__quaternion_Y
static int tolua_set_irr__core__quaternion_Y(lua_State* tolua_S)
{
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
  if (!tolua_isusertype(tolua_S,2,"f32",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Y = *((f32*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Z of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__quaternion_Z
static int tolua_get_irr__core__quaternion_Z(lua_State* tolua_S)
{
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Z'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->Z,"f32");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Z of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__quaternion_Z
static int tolua_set_irr__core__quaternion_Z(lua_State* tolua_S)
{
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Z'",NULL);
  if (!tolua_isusertype(tolua_S,2,"f32",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Z = *((f32*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: W of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__quaternion_W
static int tolua_get_irr__core__quaternion_W(lua_State* tolua_S)
{
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'W'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->W,"f32");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: W of class  irr::core::quaternion */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__quaternion_W
static int tolua_set_irr__core__quaternion_W(lua_State* tolua_S)
{
  irr::core::quaternion* self = (irr::core::quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'W'",NULL);
  if (!tolua_isusertype(tolua_S,2,"f32",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->W = *((f32*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_quaternion_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"irr",0);
  tolua_beginmodule(tolua_S,"irr");
   tolua_module(tolua_S,"core",0);
   tolua_beginmodule(tolua_S,"core");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"quaternion","irr::core::quaternion","",tolua_collect_irr__core__quaternion);
    #else
    tolua_cclass(tolua_S,"quaternion","irr::core::quaternion","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"quaternion");
     tolua_function(tolua_S,"new",tolua_quaternion_irr_core_quaternion_new00);
     tolua_function(tolua_S,"new_local",tolua_quaternion_irr_core_quaternion_new00_local);
     tolua_function(tolua_S,".call",tolua_quaternion_irr_core_quaternion_new00_local);
     tolua_function(tolua_S,"new",tolua_quaternion_irr_core_quaternion_new01);
     tolua_function(tolua_S,"new_local",tolua_quaternion_irr_core_quaternion_new01_local);
     tolua_function(tolua_S,".call",tolua_quaternion_irr_core_quaternion_new01_local);
     tolua_function(tolua_S,"new",tolua_quaternion_irr_core_quaternion_new02);
     tolua_function(tolua_S,"new_local",tolua_quaternion_irr_core_quaternion_new02_local);
     tolua_function(tolua_S,".call",tolua_quaternion_irr_core_quaternion_new02_local);
     tolua_function(tolua_S,"new",tolua_quaternion_irr_core_quaternion_new03);
     tolua_function(tolua_S,"new_local",tolua_quaternion_irr_core_quaternion_new03_local);
     tolua_function(tolua_S,".call",tolua_quaternion_irr_core_quaternion_new03_local);
     tolua_function(tolua_S,".eq",tolua_quaternion_irr_core_quaternion__eq00);
     tolua_function(tolua_S,".add",tolua_quaternion_irr_core_quaternion__add00);
     tolua_function(tolua_S,".mul",tolua_quaternion_irr_core_quaternion__mul00);
     tolua_function(tolua_S,".mul",tolua_quaternion_irr_core_quaternion__mul01);
     tolua_function(tolua_S,"dotProduct",tolua_quaternion_irr_core_quaternion_dotProduct00);
     tolua_function(tolua_S,"set",tolua_quaternion_irr_core_quaternion_set00);
     tolua_function(tolua_S,"set",tolua_quaternion_irr_core_quaternion_set01);
     tolua_function(tolua_S,"normalize",tolua_quaternion_irr_core_quaternion_normalize00);
     tolua_function(tolua_S,"getMatrix",tolua_quaternion_irr_core_quaternion_getMatrix00);
     tolua_function(tolua_S,"makeInverse",tolua_quaternion_irr_core_quaternion_makeInverse00);
     tolua_function(tolua_S,"slerp",tolua_quaternion_irr_core_quaternion_slerp00);
     tolua_function(tolua_S,"fromAngleAxis",tolua_quaternion_irr_core_quaternion_fromAngleAxis00);
     tolua_function(tolua_S,"toEuler",tolua_quaternion_irr_core_quaternion_toEuler00);
     tolua_variable(tolua_S,"X",tolua_get_irr__core__quaternion_X,tolua_set_irr__core__quaternion_X);
     tolua_variable(tolua_S,"Y",tolua_get_irr__core__quaternion_Y,tolua_set_irr__core__quaternion_Y);
     tolua_variable(tolua_S,"Z",tolua_get_irr__core__quaternion_Z,tolua_set_irr__core__quaternion_Z);
     tolua_variable(tolua_S,"W",tolua_get_irr__core__quaternion_W,tolua_set_irr__core__quaternion_W);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_quaternion (lua_State* tolua_S) {
 return tolua_quaternion_open(tolua_S);
};
#endif

