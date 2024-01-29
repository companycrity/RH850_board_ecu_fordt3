# Version of the language definition syntax used in the file
version = "1"

# language specification for syntax coloring and
# auto-indention in MULTI's editor.

%include "ghs_option_database.gsc"

language {
    general {
	# Official name for the language, like
	# 	C/C++/Pascal/Java/Ada/Fortran
	# or
	# 	GHS-Script/GHS-Linker/GHS-LanguageDefinition etc.
	name = "GHS-MULTI-Launcher"
	description = "GHS MULTI Launcher"
	# File extensions for the language
	extension = {"gmb"}

	# Inherit the definition for the following elements from
	# "ghs_option_database.gsc":
	#		keyword
	#               preprocessor 
	#		line_comment
	#		comment
	#		string
	#		character
	#		float 
	#		integer 

	# The following are some other information about the language

	# Is the language case-sensitive? If no explicit specification
	# for it, the default value is true.
	case_sensitive = false

	# Priority conflict solution.
	# Comment, string and character have the same priority.
	# When preprocessor conflicts with them, some language, like
	# C/C++, let comment, string and character have higher priority,
	# other language, like PASCAL, do the other choice.
	# We choose the behavior of C/C++ as the default behavior.
	# If you want to change, like for PASCAL, use the following 
	# statement:
	# pascal_style_priority = true

	# Separator of the language to delimit syntax tokens
	separator = "\\\"+-*/<=>:,;\'\t()[]^%!~|& {}.?"

	# Escape sequence leader: one character(like the one in C).
	escape = "\\"
    }

    keyword {
	# You can define keyword name list, the color to show the
	# keywords(optional), and indicate if to auto-complete keywords
	# when the auto-completion mechanism is on.
	name += {"version"}
	name += {"multi_launches_builder"}
	name += {"show_information"}
	name += {"concise_mode"}
	name += {"workspace"}
	# Workspace keywords
	name += {"working_dir"}
	name += {"source_dir"}
	name += {"view_position"}
	name += {"task"}

	name += {"apply_wbuild_to_bld_project"}
	name += {"create_new_project_in_gpj"}
	name += {"abort_execution_on_error"}
	name += {"show_progress_window"}
	name += {"show_auto_run_progress_window"}
	# Action keywords
	name += {"action"}
	name += {"argument"}
	name += {"enabled"}
	name += {"contracted"}
	# Variable kwywords
	name += {"variable"}
	name += {"value"}
	# Index keywords
	name += {"next_file_index"}
	name += {"next_workspace_index"}
	name += {"max_variable_substitute_depth"}
	name += {"name"}
	name += {"file"}
	# Customized keywords, like

	# If color is not defined for keyword, default color is used.
	# color = "#0000ff"
	# If auto-completion is not explicitly specified, it is true
	# by default.
	# autocomplete = false
    }

    autocomplete {
	# "match" is used to defined match algorithm, it has 
	# the following values:
	#	"best" - default value
	#	"first"
	# As an example, if there are 3 strings for auto-completion:
	# 	"main", "mail" and "misc"
	# When you type in "m", "best match" will not auto-complete it,
	# because the 3 strings do not have a common prefix beginning with
	# "m", but "first match" will auto-complete it into "main".
	# When you type in "ma", "best match" will auto-complete it
	# into "mai", but "first match" will still auto-complete it
	# into "main".
	match = "best"
	
	# By default, you can use the following key-strokes in MULTI Editor
	# to manually find an auto-completed string for the string ending
	# at the caret:
	# 1. "ctrl+]": navigate to the next matched string.
	# 2. "ctrl+[": navigate to the previous matched string.
	# You can continuously press the keys to scan the matched
	# string list until you find the one you want.
	# 3. "ctrl+/": launch a popup menu to show a list of matched
	# strings(up to a certain number configured by the following option).
	# Then you can pick what you want form the popup menu.

	# Max number of strings to match when user types "ctrl+/".
	# The default value is 10. Use the following statement to change it.
	# max_match = 15

	# Minimum length for a string to which auto-completion can be applied.
	# The default value is 1. Use the following statement to change it.
	min_string_length = 3

	# "autocomplete" let you can turn on/off the whole
	# auto-completion mechanism. The default value is true.
	# When the setting here is true, you can still turn on/off
	# about if using keywords, preprocessors or customized items
	# not containing wild card as the auto-completion source.
	# autocomplete = false

	# Define extra auto-completion items in addition to
	# 1. keywords
	# 2. preprocessors
	# 3. customized items not containing wild card

	# Auto-complete strings
	# name = {"main"}
	# name += {"strcasecmp"}
	# More stuff from library for auto-completion
	
	# More stuff from GHS-library for auto-completion
    }
}
