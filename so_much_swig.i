%module so_much_swig

%include <std_string.i>
%include exception.i

%{
  #define SWIG_FILE_WITH_INIT
  #include "so_much_swig.h"
%}

%exception {
	try
	{
		$action
	}

	catch(range_error& e)
	{
		// Because SWIG_exception only takes c_str
		string except_info("range_error: "),  except_what(e.what());
		except_info += except_what;

		SWIG_exception(SWIG_ValueError, except_info.c_str());
	}

	catch(...)
	{
		SWIG_exception(SWIG_RuntimeError, "Unknown exception");
	}
}

%include "numpy.i"

%init %{
import_array();
%}

%apply (float* INPLACE_ARRAY1, int DIM1) {(float* data, int n)};
%include "so_much_swig.h"
