// Copyright (C) 2002-2007 Nikolaus Gebhardt, modify OpenGL|ES by pham hong duc (hongduc.pr@gmail.com)
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __C_OPENGLES_SHADER_MATERIAL_RENDERER_H_INCLUDED__
#define __C_OPENGLES_SHADER_MATERIAL_RENDERER_H_INCLUDED__

#include "IrrCompileConfig.h"
#ifdef _IRR_COMPILE_WITH_OPENGL_ES_
#ifdef _IRR_HAS_SHADER

#ifdef _IRR_WINDOWS_API_
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	#include <GL/gl.h>
#else
#if defined(_IRR_OPENGL_USE_EXTPOINTER_)
	#define GL_GLEXT_LEGACY 1
#endif
#if defined(MACOSX)
	#include <OpenGL/gl.h>
#else
	#include <GL/gl.h>
#endif
#if defined(_IRR_OPENGL_USE_EXTPOINTER_)
	#include "glext.h"
#endif
#endif

#include "IMaterialRenderer.h"

namespace irr
{
namespace video
{

class COpenGLESDriver;
class IShaderConstantSetCallBack;
class IMaterialRenderer;

//! Class for using vertex and pixel shaders with OpenGL
class COpenGLESShaderMaterialRenderer : public IMaterialRenderer
{
public:

	//! Constructor
	COpenGLESShaderMaterialRenderer(video::COpenGLESDriver* driver,
		s32& outMaterialTypeNr, const c8* vertexShaderProgram, const c8* pixelShaderProgram,
		IShaderConstantSetCallBack* callback, IMaterialRenderer* baseMaterial, s32 userData);

	//! Destructor
	virtual ~COpenGLESShaderMaterialRenderer();

	virtual void OnSetMaterial(const video::SMaterial& material, const video::SMaterial& lastMaterial,
		bool resetAllRenderstates, video::IMaterialRendererServices* services);

	virtual bool OnRender(IMaterialRendererServices* service, E_VERTEX_TYPE vtxtype);

	virtual void OnUnsetMaterial();

	//! Returns if the material is transparent.
	virtual bool isTransparent() const;

protected:

	//! constructor only for use by derived classes who want to
	//! create a fall back material for example.
	COpenGLESShaderMaterialRenderer(COpenGLESDriver* driver,
					IShaderConstantSetCallBack* callback,
					IMaterialRenderer* baseMaterial, s32 userData=0);

	void init(s32& outMaterialTypeNr, const c8* vertexShaderProgram,
		const c8* pixelShaderProgram, E_VERTEX_TYPE type);

	bool createPixelShader(const c8* pxsh);
	bool createVertexShader(const char* vtxsh);

	video::COpenGLESDriver* Driver;
	IShaderConstantSetCallBack* CallBack;
	IMaterialRenderer* BaseMaterial;

	GLuint VertexShader;
	GLuint PixelShader;
	s32 UserData;
};


} // end namespace video
} // end namespace irr

#endif // #ifndef _IRR_HAS_SHADER

#endif
#endif // __C_OPENGLES_SHADER_MATERIAL_RENDERER_H_INCLUDED__