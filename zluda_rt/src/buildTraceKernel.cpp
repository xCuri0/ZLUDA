#define HIPRT_EXPORTS 1
#include <hiprt/hiprt.h>
#include <windows.h>

typedef hiprtError (*hiprtBuildTraceKernels_func)(
	hiprtContext	  context,
	uint32_t		  numFunctions,
	const char**	  funcNames,
	const char*		  src,
	const char*		  moduleName,
	uint32_t		  numHeaders,
	const char**	  headers,
	const char**	  includeNames,
	uint32_t		  numOptions,
	const char**	  options,
	uint32_t		  numGeomTypes,
	uint32_t		  numRayTypes,
	hiprtFuncNameSet* funcNameSets,
	hiprtApiFunction* functionsOut,
	hiprtApiModule*	  moduleOut,
	bool			  cache );

extern "C" {
hiprtError buildTraceKernel(
	hiprtContext	  context,
	const char*	      funcName,
	const char*		  src,
	const char*		  moduleName,
	uint32_t		  numHeaders,
	const char**	  headers,
	const char**	  includeNames,
	uint32_t		  numOptions,
	const char**	  options,
	uint32_t		  numGeomTypes,
	uint32_t		  numRayTypes,
	hiprtFuncNameSet* funcNameSets,
	hiprtApiModule*	  moduleOut,
	bool			  cache )
{
    std::vector<const char*> funcNames = {funcName};
    std::vector<hiprtApiFunction> functionsOut = {};

	functionsOut.resize(1);

    HINSTANCE hHipRt = LoadLibrary("hiprt64.dll");
    hiprtBuildTraceKernels_func func = (hiprtBuildTraceKernels_func)GetProcAddress(hHipRt, "hiprtBuildTraceKernels");

	return func(
		context,
		1,
		funcNames.data(),
		src,
		moduleName,
		numHeaders,
		headers,
		includeNames,
		numOptions,
		options,
		numGeomTypes,
		numRayTypes,
		nullptr,
		functionsOut.data(),
		moduleOut,
		cache );
}
}