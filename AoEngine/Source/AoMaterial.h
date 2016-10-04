#pragma once
#include "AoAsset.h"
#include "AoString.h"
#include "AoMatrix4x4.h"
#include <unordered_map>

class AoShader;
class AoTexture2D;
class AoMaterialProperty;
//@TODO: Initialize Properties from Shader Variables
class AoMaterial : public AoAsset
{
	friend AoAssetFactory;

protected:
	AoMaterial( AoShader* Shader );

public:
	~AoMaterial( );

	ID3DX11EffectTechnique* GetTechniqueByName( const string& PropertyName ) const;
	AoMaterialProperty* GetPropertyByName( const string& PropertyName ) const;
	int GetIntByName( const string& PropertyName ) const;
	float GetFloatByName( const string& PropertyName ) const;
	bool GetBoolByName( const string& PropertyName ) const;
	AoTexture2D* GetTextureByName( const string& PropertyName ) const;
	AoMatrix4x4 GetMatrixByName( const string& PropertyName ) const;
	AoVector4 GetVectorByName( const string& PropertyName ) const;

	void SetIntByName( const string& PropertyName, int Value );
	void SetFloatByName( const string& PropertyName, float Value );
	void SetBoolByName( const string& PropertyName, bool Value );
	void SetTextureByName( const string& PropertyName, AoTexture2D* Value );
	void SetMatrixByName( const string& PropertyName, const AoMatrix4x4& Value );
	void SetVectorByName( const string& PropertyName, const AoVector4& Value );

	void SetMaterialName( const string& Name );
	string GetMaterialName( ) const;

	void SetShader( AoShader* Shader );
	AoShader* GetShader( ) const;

	void ApplyPropertiesToShader( );

	static void SaveToFile( const string& FileFullPath, const AoMaterial* Material );

private:
	void DeleteAllProperties( );

private:
	using PropertyMap = std::unordered_map<string, AoMaterialProperty*>;
	string MaterialName;
	AoShader* Shader;
	PropertyMap Properties;

};