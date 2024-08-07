#pragma once
#include <vector>
#include <Windows.h>
#include <minwinbase.h>
#include <sysinfoapi.h>
#include "ShortTypes.h"
#include "Counter.h"
#include "Translate.h"
#include "BlockCode.h"

#ifndef macro_header_debugger
#define macro_header_debugger

namespace debug {
	using characteristic_parameter
		= booleam_parameter_char;

	using c_characteristic_parameter
		= const characteristic_parameter;

	c_characteristic_parameter characteristic_none = ~0;

	c_characteristic_parameter characteristic_critical
		= ~(1 << put_index_counter<characteristic_parameter>(0));
	c_characteristic_parameter characteristic_dangerous
		= ~(1 << put_index_counter<characteristic_parameter>(continue_counting));
	c_characteristic_parameter characteristic_logical
		= ~(1 << put_index_counter<characteristic_parameter>(continue_counting));
	c_characteristic_parameter characteristic_algebraic
		= ~(1 << put_index_counter<characteristic_parameter>(continue_counting));

	const size_t title_index_just_message
		= put_index_counter<size_t>(0);
	const size_t title_index_cannot_register_class_name
		= put_index_counter<size_t>(continue_counting);

	const size_t details_index_it_is_a_test
		= put_index_counter<size_t>(0);
	const size_t details_index_cannot_register_main_class_name
		= put_index_counter<size_t>(continue_counting);
	const size_t details_index_cannot_register_debugger_class_name
		= put_index_counter<size_t>(continue_counting);
	const size_t details_index_cannot_register_unknown_class_name
		= put_index_counter<size_t>(continue_counting);

	using event_type_index = u_char_;
	using c_event_type_index = const event_type_index;

	c_event_type_index event_type_message
		= put_index_counter<event_type_index>(0);
	c_event_type_index event_type_question
		= put_index_counter<event_type_index>(continue_counting);
	c_event_type_index event_type_warning
		= put_index_counter<event_type_index>(continue_counting);
	c_event_type_index event_type_error
		= put_index_counter<event_type_index>(continue_counting);

	class event_information {
	public:
		event_type_index event_type = event_type_message;
		characteristic_parameter characteristic = ~0;

		size_t title_index = 0;
		size_t details_index = 0;
		std::vector<std::size_t> reason_index_list{};
		std::vector<std::size_t> advance_index_list{};

		std::vector<coding::block_information> block_array{};

		SYSTEMTIME time_system{};
		SYSTEMTIME time_local{};

		translate::string show_type( ) {
			if ( event_type == event_type_message ) {
				return translate::set_string(
					L"Message",
					L"���������"
				);
			}
			else if ( event_type == event_type_question ) {
				return translate::set_string(
					L"Question",
					L"������"
				);
			}
			else if ( event_type == event_type_warning ) {
				return translate::set_string(
					L"Warning",
					L"��������������"
				);
			}
			else if ( event_type == event_type_error ) {
				return translate::set_string(
					L"Error",
					L"������"
				);
			}

			return translate::set_string(
				L"Where is type?",
				L"��� ���?"
			);
		}

		translate::string show_title( ) {
			if ( title_index == title_index_just_message ) {
				return translate::set_string(
					L"Just a message",
					L"������ ���������"
				);
			}
			else if ( title_index == title_index_cannot_register_class_name ) {
				return translate::set_string(
					L"Couldn't create class' name",
					L"�� ������� ������� ��� ������"
				);
			}

			return translate::set_string(
				L"Where is title?",
				L"��� ���������?"
			);
		}

		translate::string show_details( ) {
			if ( details_index == details_index_it_is_a_test ) {
				return translate::set_string(
					L"This is a test",
					L"��� �������� ������"
				);
			}
			else if ( details_index == details_index_cannot_register_main_class_name ) {
				return translate::set_string(
					L"Couldn't create class' name for main window",
					L"�� ������� ������� ��� ������ ��� �������� ����"
				);
			}
			else if ( details_index == details_index_cannot_register_debugger_class_name ) {
				return translate::set_string(
					L"Couldn't create class' name for debugger's window",
					L"�� ������� ������� ��� ������ ��� ���� ���������"
				);
			}
			else if ( details_index == details_index_cannot_register_unknown_class_name ) {
				return translate::set_string(
					L"Couldn't create class' name for unknown window",
					L"�� ������� ������� ��� ������ ��� ������������ ����"
				);
			}

			return translate::set_string(
				L"Where is details?",
				L"��� �����������?"
			);
		}
	};

	std::vector<event_information> history_of_event{};

	void write_event(
		event_type_index event_type,
		characteristic_parameter characteristic,
		size_t title_index,
		size_t details_index,
		std::vector<std::size_t> reason_index_list,
		std::vector<std::size_t> advance_index_list,
		std::vector<coding::block_information> block_array
	) {
		history_of_event.push_back(
			{
				event_type,
				characteristic,
				title_index,
				details_index,
				reason_index_list,
				advance_index_list,
				block_array
			}
		);

		GetSystemTime(&history_of_event.back( ).time_system);
		GetLocalTime(&history_of_event.back( ).time_local);
	}
}

#endif
