
#include <node_api.h>
#include <vector>
#include <string>


#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_recursive_mutex.hpp>


napi_value Hello(napi_env env, napi_callback_info info)
{
	napi_value result = nullptr;
	size_t args_count = 1;
	napi_value args[1];
	napi_status status = napi_get_cb_info(env, info, &args_count, args, nullptr, nullptr);
	if (status == napi_ok)
	{
		napi_valuetype type = napi_undefined;
		napi_status status = napi_typeof(env, args[0], &type);
		if ((status == napi_ok) && (type == napi_string))
		{
			size_t buffersize = 0;
			napi_status status = napi_get_value_string_utf8(env, args[0], nullptr, 0, &buffersize);
			if ((status == napi_ok) && (buffersize > 0))
			{
				std::vector<char> buffer(buffersize + 1);
				napi_status status = napi_get_value_string_utf8(env, args[0], buffer.data(), buffersize + 1, nullptr);
				if (status == napi_ok)
				{
					std::string hello_string("Hello ");
					hello_string.append(buffer.data());
					hello_string.append(" !");
					status = napi_create_string_utf8(env, hello_string.c_str(), NAPI_AUTO_LENGTH, &result);
				}
			}
		}
	}

	if ((status == napi_ok) && (result == nullptr))
	{
		status = napi_create_string_utf8(env, "Hello from Test Addon Module !", NAPI_AUTO_LENGTH, &result);
	}

	return result;
}


napi_value InitModule(napi_env env, napi_value exports)
{
	napi_property_descriptor desc[] = {
		{ "hello", nullptr, Hello, nullptr, nullptr, nullptr, napi_default, nullptr}
	};

	napi_status status = napi_define_properties(env, exports, 1, desc);

	return exports;
}


NAPI_MODULE(NODE_MODULE_NAME, InitModule)