#include "AoVector.h"
#include "AoMath.h"

const AoVector AoVector::Zero = AoVector( 0.0f, 0.0f, 0.0f );
const AoVector AoVector::One = AoVector( 1.0f, 1.0f, 1.0f );

AoVector::AoVector( float X, float Y, float Z ) :
	X( X ),
	Y( Y ),
	Z( Z )
{
}

AoVector& AoVector::operator=( const AoVector& Operand )
{
	X = Operand.X;
	Y = Operand.Y;
	Z = Operand.Z;
	return *this;
}

AoVector AoVector::operator+( float Operand )
{
	return AoVector(
		X + Operand,
		Y + Operand,
		Z + Operand );
}

AoVector AoVector::operator+( const AoVector& Operand )
{
	return AoVector( 
		X + Operand.X,
		Y + Operand.Y,
		Z + Operand.Z );
}

AoVector& AoVector::operator+=( float Operand )
{
	X += Operand;
	Z += Operand;
	Y += Operand;
	return *this;
}

AoVector& AoVector::operator+=( const AoVector& Operand )
{
	X += Operand.X;
	Y += Operand.Y;
	Z += Operand.Z;
	return *this;
}

AoVector AoVector::operator-( float Operand )
{
	return AoVector(
		X - Operand,
		Y - Operand,
		Z - Operand );
}

AoVector AoVector::operator-( const AoVector & Operand )
{
	return AoVector( 
		X - Operand.X,
		Y - Operand.Y,
		Z - Operand.Z );
}

AoVector& AoVector::operator-=( float Operand )
{
	X -= Operand;
	Y -= Operand;
	Z -= Operand;
	return *this;
}

AoVector& AoVector::operator-=( const AoVector& Operand )
{
	X -= Operand.X;
	Y -= Operand.Y;
	Z -= Operand.Z;
	return *this;
}

AoVector AoVector::operator*( float Operand )
{
	return AoVector(
		X * Operand,
		Y * Operand,
		Z * Operand );
}

AoVector AoVector::operator*( const AoVector& Operand )
{
	return AoVector(
		X * Operand.X,
		Y * Operand.Y,
		Z * Operand.Z );
}

AoVector& AoVector::operator*=( float Operand )
{
	X *= Operand;
	Y *= Operand;
	Z *= Operand;
	return *this;
}

AoVector& AoVector::operator*=( const AoVector& Operand )
{
	X *= Operand.X;
	Y *= Operand.Y;
	Z *= Operand.Z;
	return *this;
}

AoVector AoVector::operator/( float Operand )
{
	float InvOperand = 1.0f / Operand;
	return AoVector( 
		X * InvOperand,
		Y * InvOperand, 
		Z * InvOperand );
}

AoVector AoVector::operator/( const AoVector& Operand )
{
	return AoVector(
		X / Operand.X,
		Y / Operand.Y,
		Z / Operand.Z );
}

AoVector& AoVector::operator/=( float Operand )
{
	float InvOperand = 1.0f / Operand;
	X *= InvOperand;
	Y *= InvOperand;
	Z *= InvOperand;
	return *this;
}

AoVector& AoVector::operator/=( const AoVector& Operand )
{
	X /= Operand.X;
	Y /= Operand.Y;
	Z /= Operand.Z;
	return *this;
}

float AoVector::operator|( const AoVector& Operand )
{
	return ( X * Operand.X + Y * Operand.Y + Z * Operand.Z );
}

AoVector AoVector::operator^( const AoVector& Operand )
{
	return  AoVector(
		Y*Operand.Z - Z*Operand.Y,
		Z*Operand.X - X*Operand.Z,
		X*Operand.Y - Y*Operand.X );
}

void AoVector::SetX( float X )
{
	this->X = X;
}

float AoVector::GetX() const
{
	return X;
}

void AoVector::SetY( float Y )
{
	this->Y = Y;
}

float AoVector::GetY() const
{
	return Y;
}

void AoVector::SetZ( float Z )
{
	this->Z = Z;
}

float AoVector::GetZ() const
{
	return Z;
}

float AoVector::Size() const
{
	return sqrtf( ( X * X + Y * Y + Z * Z ) );
}

float AoVector::SquaredSize() const
{
	return ( X * X + Y * Y + Z * Z );
}

void AoVector::Normalize()
{
	float InvSize = 1.0f / Size();
	X *= InvSize;
	Y *= InvSize;
	Z *= InvSize;
}

AoVector AoVector::GetNormal() const
{
	float InvSize = 1.0f / Size();
	return AoVector( X * InvSize, Y * InvSize, Z * InvSize );
}

bool AoVector::IsUnit() const
{
	return ( Size() == 1.0f );
}

bool AoVector::IsOne() const
{
	return ( X == 1.0f && Y == 1.0f && Z == 1.0f );
}

bool AoVector::IsZero() const
{
	return ( X == 0.0f && Y == 0.0f && Z == 0.0f );
}