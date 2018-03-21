{
	"targets": [{
		"target_name": "test_addon_simple_hello",
		"sources": [
			"src/entry_point.cpp"
		],
		"include_dirs": [
			"src",
			"deps"
		],
		"defines": [
			"BOOST_DATE_TIME_NO_LIB"
		]
	}]
}