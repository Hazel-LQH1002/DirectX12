float4 main( float2 pos : POSITION ) : SV_Position //system value
{
	return float4(pos.x, pos.y, 0.0f, 1.0f);
}