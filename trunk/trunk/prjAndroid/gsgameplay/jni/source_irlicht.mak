LOCAL_C_INCLUDES := ../../../../extern/irrogles/include \
../../../../extern/irrogles/source/Irrlicht/zlib 

LOCAL_CFLAGS := -DIRRLICHT_EXPORTS \
-DANDROID 

LOCAL_SRC_FILES := ../../../../extern/irrogles/source/Irrlicht/C3DSMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CAnimatedMeshHalfLife.cpp \
../../../../extern/irrogles/source/Irrlicht/CAnimatedMeshMD2.cpp \
../../../../extern/irrogles/source/Irrlicht/CAnimatedMeshMD3.cpp \
../../../../extern/irrogles/source/Irrlicht/CB3DMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CBSPMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CColladaFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CCSMLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CDMFLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CIrrMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CLMTSMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CLWOMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CMD2MeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CMD3MeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CMS3DMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CMY3DMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/COBJMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/COCTLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/COgreMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CPLYMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CQ3LevelMesh.cpp \
../../../../extern/irrogles/source/Irrlicht/CSkinnedMesh.cpp \
../../../../extern/irrogles/source/Irrlicht/CSMFMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CSTLMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CXMeshFileLoader.cpp \
../../../../extern/irrogles/source/Irrlicht/CAnimatedMeshSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CBillboardSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CBoneSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CCameraSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CCubeSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CDummyTransformationSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CEmptySceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CLightSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CMeshSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/COctreeSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CQuake3ShaderSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CShadowVolumeSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CSkyBoxSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CSkyDomeSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CSphereSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CTerrainSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CTextSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CVolumeLightSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CWaterSurfaceSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleAnimatedMeshSceneNodeEmitter.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleAttractionAffector.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleBoxEmitter.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleCylinderEmitter.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleFadeOutAffector.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleGravityAffector.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleMeshEmitter.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticlePointEmitter.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleRingEmitter.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleRotationAffector.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleScaleAffector.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleSphereEmitter.cpp \
../../../../extern/irrogles/source/Irrlicht/CParticleSystemSceneNode.cpp \
../../../../extern/irrogles/source/Irrlicht/CMetaTriangleSelector.cpp \
../../../../extern/irrogles/source/Irrlicht/COctreeTriangleSelector.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneCollisionManager.cpp \
../../../../extern/irrogles/source/Irrlicht/CTerrainTriangleSelector.cpp \
../../../../extern/irrogles/source/Irrlicht/CTriangleBBSelector.cpp \
../../../../extern/irrogles/source/Irrlicht/CTriangleSelector.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneNodeAnimatorCameraFPS.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneNodeAnimatorCameraMaya.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneNodeAnimatorCollisionResponse.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneNodeAnimatorDelete.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneNodeAnimatorFlyCircle.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneNodeAnimatorFlyStraight.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneNodeAnimatorFollowSpline.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneNodeAnimatorRotation.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneNodeAnimatorTexture.cpp \
../../../../extern/irrogles/source/Irrlicht/CColladaMeshWriter.cpp \
../../../../extern/irrogles/source/Irrlicht/CIrrMeshWriter.cpp \
../../../../extern/irrogles/source/Irrlicht/COBJMeshWriter.cpp \
../../../../extern/irrogles/source/Irrlicht/CPLYMeshWriter.cpp \
../../../../extern/irrogles/source/Irrlicht/CSTLMeshWriter.cpp \
../../../../extern/irrogles/source/Irrlicht/CDefaultSceneNodeAnimatorFactory.cpp \
../../../../extern/irrogles/source/Irrlicht/CDefaultSceneNodeFactory.cpp \
../../../../extern/irrogles/source/Irrlicht/CGeometryCreator.cpp \
../../../../extern/irrogles/source/Irrlicht/CMeshCache.cpp \
../../../../extern/irrogles/source/Irrlicht/CMeshManipulator.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneLoaderIrr.cpp \
../../../../extern/irrogles/source/Irrlicht/CSceneManager.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLESDriver.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLESExtensionHandler.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLESTexture.cpp \
../../../../extern/irrogles/source/Irrlicht/CSoftwareDriver.cpp \
../../../../extern/irrogles/source/Irrlicht/CSoftwareTexture.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRFlat.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRFlatWire.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRGouraud.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRGouraudWire.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureFlat.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureFlatWire.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraud.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraudAdd.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraudNoZ.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraudWire.cpp \
../../../../extern/irrogles/source/Irrlicht/CZBuffer.cpp \
../../../../extern/irrogles/source/Irrlicht/COpenGLDriver.cpp \
../../../../extern/irrogles/source/Irrlicht/COpenGLExtensionHandler.cpp \
../../../../extern/irrogles/source/Irrlicht/COpenGLNormalMapRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/COpenGLParallaxMapRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/COpenGLShaderMaterialRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/COpenGLSLMaterialRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/COpenGLTexture.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D8Driver.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D8NormalMapRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D8ParallaxMapRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D8ShaderMaterialRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D8Texture.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageWriterBMP.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageWriterJPG.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageWriterPCX.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageWriterPNG.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageWriterPPM.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageWriterPSD.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageWriterTGA.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageLoaderBMP.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageLoaderDDS.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageLoaderJPG.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageLoaderPCX.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageLoaderPNG.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageLoaderPPM.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageLoaderPSD.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageLoaderRGB.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageLoaderTGA.cpp \
../../../../extern/irrogles/source/Irrlicht/CImageLoaderWAL.cpp \
../../../../extern/irrogles/source/Irrlicht/CColorConverter.cpp \
../../../../extern/irrogles/source/Irrlicht/CFPSCounter.cpp \
../../../../extern/irrogles/source/Irrlicht/CImage.cpp \
../../../../extern/irrogles/source/Irrlicht/CNullDriver.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D9Driver.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D9HLSLMaterialRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D9NormalMapRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D9ParallaxMapRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D9ShaderMaterialRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/CD3D9Texture.cpp \
../../../../extern/irrogles/source/Irrlicht/CBurningShader_Raster_Reference.cpp \
../../../../extern/irrogles/source/Irrlicht/CDepthBuffer.cpp \
../../../../extern/irrogles/source/Irrlicht/CSoftwareDriver2.cpp \
../../../../extern/irrogles/source/Irrlicht/CSoftwareTexture2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRGouraud2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRGouraudAlpha2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRGouraudAlphaNoZ2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRNormalMap.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRStencilShadow.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureBlend.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureDetailMap2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraud2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraudAdd2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraudAddNoZ2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraudAlpha.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraudAlphaNoZ.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraudNoZ2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureGouraudVertexAlpha2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureLightMap2_Add.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureLightMap2_M1.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureLightMap2_M2.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureLightMap2_M4.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureLightMapGouraud2_M4.cpp \
../../../../extern/irrogles/source/Irrlicht/CTRTextureWire2.cpp \
../../../../extern/irrogles/source/Irrlicht/IBurningShader.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLES2Driver.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLES2ExtensionHandler.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLES2FixedPipelineShader.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLES2NormalMapRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLES2ParallaxMapRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLES2Renderer2D.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLES2SLMaterialRenderer.cpp \
../../../../extern/irrogles/source/Irrlicht/COGLES2Texture.cpp \
../../../../extern/irrogles/source/Irrlicht/CVideoModeList.cpp \
../../../../extern/irrogles/source/Irrlicht/CIrrDeviceAndroid.cpp \
../../../../extern/irrogles/source/Irrlicht/CIrrDeviceConsole.cpp \
../../../../extern/irrogles/source/Irrlicht/CIrrDeviceFB.cpp \
../../../../extern/irrogles/source/Irrlicht/CIrrDeviceLinux.cpp \
../../../../extern/irrogles/source/Irrlicht/CIrrDeviceSDL.cpp \
../../../../extern/irrogles/source/Irrlicht/CIrrDeviceStub.cpp \
../../../../extern/irrogles/source/Irrlicht/CIrrDeviceWin32.cpp \
../../../../extern/irrogles/source/Irrlicht/CIrrDeviceWinCE.cpp \
../../../../extern/irrogles/source/Irrlicht/CLogger.cpp \
../../../../extern/irrogles/source/Irrlicht/COSOperator.cpp \
../../../../extern/irrogles/source/Irrlicht/Irrlicht.cpp \
../../../../extern/irrogles/source/Irrlicht/os.cpp \
../../../../extern/irrogles/source/Irrlicht/CAttributes.cpp \
../../../../extern/irrogles/source/Irrlicht/CFileList.cpp \
../../../../extern/irrogles/source/Irrlicht/CFileSystem.cpp \
../../../../extern/irrogles/source/Irrlicht/CLimitReadFile.cpp \
../../../../extern/irrogles/source/Irrlicht/CMemoryFile.cpp \
../../../../extern/irrogles/source/Irrlicht/CMountPointReader.cpp \
../../../../extern/irrogles/source/Irrlicht/CNPKReader.cpp \
../../../../extern/irrogles/source/Irrlicht/CPakReader.cpp \
../../../../extern/irrogles/source/Irrlicht/CReadFile.cpp \
../../../../extern/irrogles/source/Irrlicht/CTarReader.cpp \
../../../../extern/irrogles/source/Irrlicht/CWADReader.cpp \
../../../../extern/irrogles/source/Irrlicht/CWriteFile.cpp \
../../../../extern/irrogles/source/Irrlicht/CXMLReader.cpp \
../../../../extern/irrogles/source/Irrlicht/CXMLWriter.cpp \
../../../../extern/irrogles/source/Irrlicht/CZipReader.cpp \
../../../../extern/irrogles/source/Irrlicht/irrXML.cpp \