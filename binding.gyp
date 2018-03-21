{
	"targets":
	[
		{
			"target_name": "test_addon_simple_hello",
			"sources":
			[
				"src/entry_point.cpp"
			],
			"include_dirs":
			[
				"src",
				"deps"
			],
	        "cflags!": ["-fno-rtti", "-fno-exceptions"],
	        "cflags+": ["-frtti", "-fexceptions"],
			"conditions":
			[
				[
					'OS=="mac"',
					{
			           	"xcode_settings":
			           	{
			             	"OTHER_CPLUSPLUSFLAGS" : ["-std=c++11", "-stdlib=libc++"],
			             	"OTHER_LDFLAGS": ["-stdlib=libc++"],
		                    "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
                        	"GCC_ENABLE_CPP_RTTI": "YES"
			           	}
		        	}
		        ]
			],
			"defines":
			[
				"BOOST_DATE_TIME_NO_LIB"
			]
		}
	]
}