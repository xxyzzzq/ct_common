SUBDIRS = src doc

EXTRA_DIST = build quex Doxyfile mainpage.dox

dist-hook:
	rm -rf `find $(distdir) -name .svn`

install-exe-hook:
	ldconfig

nobase_include_HEADERS = \
quex/code_base/buffer/Buffer_debug \
quex/code_base/buffer/MemoryPositionMimiker \
quex/code_base/buffer/Buffer \
quex/code_base/buffer/asserts \
quex/code_base/buffer/BufferFiller.i \
quex/code_base/buffer/Buffer.i \
quex/code_base/buffer/Buffer_debug.i \
quex/code_base/buffer/BufferFiller \
quex/code_base/buffer/InputPolicy \
quex/code_base/buffer/plain/BufferFiller_Plain \
quex/code_base/buffer/plain/BufferFiller_Plain.i \
quex/code_base/token/TokenQueue.i \
quex/code_base/token/TokenQueue \
quex/code_base/token/TokenPolicy \
quex/code_base/aux-string \
quex/code_base/aux-string.i \
quex/code_base/MemoryManager \
quex/code_base/temporary_macros_off \
quex/code_base/asserts \
quex/code_base/compatibility/iconv-argument-types.h \
quex/code_base/compatibility/stdbool.h \
quex/code_base/compatibility/stdbool-pseudo.h \
quex/code_base/compatibility/win/msc_stdint.h \
quex/code_base/compatibility/win/borland_stdint.h \
quex/code_base/compatibility/stdint.h \
quex/code_base/temporary_macros_on \
quex/code_base/definitions \
quex/code_base/converter_helper/from-utf32.i \
quex/code_base/converter_helper/from-unicode-buffer \
quex/code_base/converter_helper/from-utf8.i \
quex/code_base/converter_helper/from-unicode-buffer.i \
quex/code_base/converter_helper/from-utf32 \
quex/code_base/converter_helper/identity.i \
quex/code_base/converter_helper/from-utf16 \
quex/code_base/converter_helper/from-utf8 \
quex/code_base/converter_helper/generator/character-converter-to-char-wchar_t.gi \
quex/code_base/converter_helper/generator/implementations.gi \
quex/code_base/converter_helper/generator/string-converter.gi \
quex/code_base/converter_helper/generator/declarations.g \
quex/code_base/converter_helper/identity \
quex/code_base/converter_helper/common.h \
quex/code_base/converter_helper/from-utf16.i \
quex/code_base/include-guard-undef \
quex/code_base/MemoryManager.i \
quex/code_base/analyzer/Accumulator \
quex/code_base/analyzer/headers.i \
quex/code_base/analyzer/asserts.i \
quex/code_base/analyzer/configuration/validation \
quex/code_base/analyzer/configuration/derived \
quex/code_base/analyzer/configuration/undefine \
quex/code_base/analyzer/Accumulator.i \
quex/code_base/analyzer/member/basic \
quex/code_base/analyzer/member/include-stack.i \
quex/code_base/analyzer/member/include-stack \
quex/code_base/analyzer/member/navigation \
quex/code_base/analyzer/member/token-sending-undef.i \
quex/code_base/analyzer/member/mode-handling \
quex/code_base/analyzer/member/on_indentation.i \
quex/code_base/analyzer/member/misc \
quex/code_base/analyzer/member/constructor \
quex/code_base/analyzer/member/token-sending \
quex/code_base/analyzer/member/token-receiving.i \
quex/code_base/analyzer/member/navigation.i \
quex/code_base/analyzer/member/buffer-access \
quex/code_base/analyzer/member/buffer-access.i \
quex/code_base/analyzer/member/mode-handling.i \
quex/code_base/analyzer/member/constructor.i \
quex/code_base/analyzer/member/token-receiving \
quex/code_base/analyzer/member/misc.i \
quex/code_base/analyzer/member/basic.i \
quex/code_base/analyzer/Engine_body \
quex/code_base/analyzer/asserts \
quex/code_base/analyzer/headers \
quex/code_base/analyzer/Mode.i \
quex/code_base/analyzer/Counter.i \
quex/code_base/analyzer/Mode \
quex/code_base/analyzer/Counter \
quex/code_base/analyzer/C-adaptions.h \
quex/code_base/analyzer/EngineMemento_body
