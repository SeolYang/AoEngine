#pragma once
#include "AoShader.h"

class AoMaterialIntProperty;
class AoMaterialFloatProperty;
class AoMaterialBoolProperty;
class AoMaterialMatrixProperty;
class AoMaterialTextureProperty;
class AoMaterialProperty
{
public:
	AoMaterialProperty( const string& Name );

	virtual void ApplyToGlobalVariable( AoShader* Shader ) const = 0;

	string GetName( ) const;
	void SetName( const string& Name );

protected:
	string Name;

};
