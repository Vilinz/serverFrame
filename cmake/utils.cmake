function(force_redefine_file_macro_for_source targetname)
	get_target_property(source_files "${targetname}" SOURCES)
	foreach(sourcefile ${source_files})
		get_property(defs SOURCE "${sourcefile}" PROPERTY COMPILE_DEFINITIONS)
		get_filename_component(filepath "${sourcefile}" ABSOLUTE)
		string(REPLACE ${PROJECT_SOURCE_DIR}/ "" repath ${filepath})
		list(APPEND defs "__FILE__=\"${relpath}\"")
		set_property(
			SOURCE "${sourcefile}"
			PROPERTY COMPILE_DEFINITIONS ${defs}
			)
	endforeach()
endfunction()

function(vilin_add_executable targetname srcs depends libs)
	add_executable(${targetname} ${srcs})
	add_dependencies(${targetname} ${depends})
	# force_redefine_file_macro_for_source(${targetname})
	target_link_libraries(${targetname} ${libs})
endfunction()