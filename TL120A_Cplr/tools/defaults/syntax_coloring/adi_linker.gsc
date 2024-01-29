# Version of the language definition syntax used in the file
version = "1"

%include "c_style_preprocessors_internal.gsc"
# To define the color for preprocessors, use a statement like the
# following one, otherwise, the default color is used:
# language.preprocessor.color = "#008080"

# language specification for syntax coloring and
# auto-indention in MULTI's editor.
language {
    general {
	# Official name for the language, like
	# 	C/C++/Pascal/Java/Ada/Fortran
	# or
	# 	GHS-Script/GHS-Linker/GHS-LanguageDefinition etc.
	name = "ADI-Linker"
	description = "ADI Linker Language"
	extension = {"ldf"}

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
	# "." is not treated as separator
	separator = "\\\"+-*/<=>:,;\'\n\r\t()[]^%!~|& {}?"

	# Escape sequence leader: one character(like the one in C).
	# escape = "\\"
	}
	
    keyword {
	# You can define keyword name list, the color to show the
	# keywords(optional), and indicate if to auto-complete keywords
	# when the auto-completion mechanism is on.

        name += {"ABSOLUTE"}
	name += {"ADDR"}
	name += {"ALGORITHM"}
	name += {"ALIGN"}
	name += {"ALL_FIT"}
	name += {"ARCHITECTURE"}
	name += {"BEST_FIT"}
	name += {"BOOT"}
	name += {"COMAP"}
	name += {"DEFINED"}
	name += {"DYNAMIC"}
	name += {"ELIMINATE"}
	name += {"ELIMINATE_SECTIONS"}
	name += {"END"}
	name += {"FALSE"}
	name += {"FILL"}
	name += {"FIRST_FIT"}
	name += {"INCLUDE"}
	name += {"INPUT_SECTION_ALIGN"}
	name += {"INPUT_SECTIONS"}
	name += {"KEEP"}
	name += {"LENGTH"}
	name += {"LINK_AGAINST"}
	name += {"MAP"}
	name += {"MEMORY"}
	name += {"MEMORY_SIZEOF"}
	name += {"NUMBER_OF_OVERLAYS"}
	name += {"OUTPUT"}
	name += {"OVERLAY_GROUP"}
	name += {"OVERLAY_ID"}
	name += {"OVERLAY_INPUT"}
	name += {"OVERLAY_OUTPUT"}
	name += {"PACKING"}
	name += {"PLIT"}
	name += {"PLIT_DATA_OVERLAY_IDS"}
	name += {"PLIT_SYMBOL_ADDRESS"}
	name += {"PLIT_SYMBOL_OVERLAYID"}
	name += {"PROCESSOR"}
	name += {"RAM"}
	name += {"RESOLVE"}
	name += {"RESOLVE_LOCALLY"}
	name += {"ROM"}
	name += {"SEARCH_DIR"}
	name += {"SECTIONS"}
	name += {"SHARED_MEMORY"}
	name += {"SHT_NOBITS"}
	name += {"SIZE"}
	name += {"SIZEOF"}
	name += {"START"}
	name += {"TRUE"}
	name += {"TYPE"}
	name += {"VERBOSE"}
	name += {"WIDTH"}
	name += {"XREF"}
	
	# Customized keywords

	# If color is not defined for keyword, default color is used.
	# color = "#0000ff"
	# If auto-completion is not explicitly specified, it is true
	# by default.
	# autocomplete = false
    }

    line_comment {
	# Because multiple line comment leaders can be defined,
	# use an index for each of them.
	1 = "//"
	# If color is not defined for line_comment, default color is used.
	# color = "#008000"
    }

    comment {
	# Because multiple pairs of comment delimiters can be defined,
	# use a index for each of them.
	1 { begin = "/*"; end = "*/" }
	# If color is not defined for comment, default color is used.
	# color = "#008000"
    }

    string {
	# Because multiple pair of string delimiters can be defined,
	# use an index for each of them.
	1 { begin = "\""; end = "\"" }
	# If color is not defined for string, default color is used.
	# color = "#008000"
    }

    character {
	# Because multiple pair of string delimiters can be defined,
	# use an index for each of them.
	1 { begin = "\'"; end = "\'" }
	# If color is not defined for character, default color is used.
	# color = "#008000"
    }

    integer {
	# Support hex integer?
	hex = true
	# Case-sensitive for integer suffix? Default is true.
	case_sensitive = false
	decimal_suffix = {"k"}
	hex_suffix = {"k"}
	# If color is not defined for integer, default color is used.
	# color = "#008000"
    }

    float {
	# Support scientific float?
	scientific = true
	# Case-sensitive for float suffix? Default is true.
	# case_sensitive = false
	# If color is not defined for float, default color is used.
	# color = "#008000"
    }

    customized {
        # special symbols
        # pattern += {"something"}

        pattern += {"$COMMAND_LINE_OBJECTS"}
	pattern += {"$COMMAND_LINE_LINK_AGAINST"}
	pattern += {"$COMMAND_LINE_OUTPUT_FILE"}
	pattern += {"$ADI_DSP"}

        # constants

        # normal memory segments

        # normal sections
	pattern += {"program"}
	pattern += {"data1"}
	pattern += {"constdata"}
	pattern += {"heap"}
	pattern += {"stack"}
	pattern += {"sysstack"}
	pattern += {"bootup"}
	pattern += {"ctor"}
	pattern += {"argv"}

        # More normal sections

        # Base sections

        # ROM/CROM sections
	
	# More customized stuff.
	# If color is not defined for customized items, default color is used.
	# color = "#0080a0"
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
