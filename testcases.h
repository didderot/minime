
#ifndef _TESTCASES_H
#define _TESTCASES_H

void CWE121_Stack_Based_Buffer_Overflow__CWE129_connect_socket_01_bad();
void CWE121_Stack_Based_Buffer_Overflow__CWE129_connect_socket_01_good();

void CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memcpy_01_bad();
void CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memcpy_01_good();

void CWE123_Write_What_Where_Condition__connect_socket_01_bad();
void CWE123_Write_What_Where_Condition__connect_socket_01_good();

void CWE124_Buffer_Underwrite__CWE839_fgets_01_bad();
void CWE124_Buffer_Underwrite__CWE839_fgets_01_good();

void CWE126_Buffer_Overread__CWE129_fscanf_01_bad();
void CWE126_Buffer_Overread__CWE129_fscanf_01_good();

void CWE127_Buffer_Underread__CWE839_listen_socket_01_bad();
void CWE127_Buffer_Underread__CWE839_listen_socket_01_good();

void CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_01_bad();
void CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_01_good();

void CWE188_Reliance_on_Data_Memory_Layout__modify_local_01_bad();
void CWE188_Reliance_on_Data_Memory_Layout__modify_local_01_good();

void CWE190_Integer_Overflow__char_fscanf_add_01_bad();
void CWE190_Integer_Overflow__char_fscanf_add_01_good();

void CWE191_Integer_Underflow__char_fscanf_multiply_01_bad();
void CWE191_Integer_Underflow__char_fscanf_multiply_01_good();

void CWE194_Unexpected_Sign_Extension__connect_socket_malloc_01_bad();
void CWE194_Unexpected_Sign_Extension__connect_socket_malloc_01_good();

void CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memcpy_01_bad();
void CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memcpy_01_good();

void CWE196_Unsigned_to_Signed_Conversion_Error__basic_01_bad();
void CWE196_Unsigned_to_Signed_Conversion_Error__basic_01_good();

void CWE197_Numeric_Truncation_Error__int_fgets_to_short_01_bad();
void CWE197_Numeric_Truncation_Error__int_fgets_to_short_01_good();

void CWE252_Unchecked_Return_Value__char_fread_01_bad();
void CWE252_Unchecked_Return_Value__char_fread_01_good();

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01_bad();
void CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01_good();

void CWE364_Signal_Handler_Race_Condition__basic_01_bad();
void CWE364_Signal_Handler_Race_Condition__basic_01_good();

void CWE366_Race_Condition_Within_Thread__global_int_01_bad();
void CWE366_Race_Condition_Within_Thread__global_int_01_good();

void CWE367_TOC_TOU__access_01_bad();
void CWE367_TOC_TOU__access_01_good();

void CWE369_Divide_by_Zero__float_rand_01_bad();
void CWE369_Divide_by_Zero__float_rand_01_good();

void CWE377_Insecure_Temporary_File__char_mktemp_01_bad();
void CWE377_Insecure_Temporary_File__char_mktemp_01_good();

void CWE391_Unchecked_Error_Condition__sqrt_01_bad();
void CWE391_Unchecked_Error_Condition__sqrt_01_good();

void CWE398_Poor_Code_Quality__addition_01_bad();
void CWE398_Poor_Code_Quality__addition_01_good();

void CWE400_Resource_Exhaustion__connect_socket_sleep_01_bad();
void CWE400_Resource_Exhaustion__connect_socket_sleep_01_good();

void CWE401_Memory_Leak__char_calloc_01_bad();
void CWE401_Memory_Leak__char_calloc_01_good();

void CWE404_Improper_Resource_Shutdown__open_fclose_01_bad();
void CWE404_Improper_Resource_Shutdown__open_fclose_01_good();

void CWE415_Double_Free__malloc_free_char_01_bad();
void CWE415_Double_Free__malloc_free_char_01_good();

void CWE416_Use_After_Free__malloc_free_char_01_bad();
void CWE416_Use_After_Free__malloc_free_char_01_good();

void CWE426_Untrusted_Search_Path__char_popen_01_bad();
void CWE426_Untrusted_Search_Path__char_popen_01_good();

void CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_01_bad();
void CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_01_good();

void CWE457_Use_of_Uninitialized_Variable__char_pointer_01_bad();
void CWE457_Use_of_Uninitialized_Variable__char_pointer_01_good();

void CWE459_Incomplete_Cleanup__char_01_bad();
void CWE459_Incomplete_Cleanup__char_01_good();

void CWE464_Addition_of_Data_Structure_Sentinel__basic_01_bad();
void CWE464_Addition_of_Data_Structure_Sentinel__basic_01_good();

void CWE467_Use_of_sizeof_on_Pointer_Type__char_01_bad();
void CWE467_Use_of_sizeof_on_Pointer_Type__char_01_good();

void CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01_bad();
void CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01_good();

void CWE469_Use_of_Pointer_Subtraction_to_Determine_Size__char_01_bad();
void CWE469_Use_of_Pointer_Subtraction_to_Determine_Size__char_01_good();

void CWE475_Undefined_Behavior_for_Input_to_API__char_01_bad();
void CWE475_Undefined_Behavior_for_Input_to_API__char_01_good();

void CWE476_NULL_Pointer_Dereference__binary_if_01_bad();
void CWE476_NULL_Pointer_Dereference__binary_if_01_good();

void CWE478_Missing_Default_Case_in_Switch__basic_01_bad();
void CWE478_Missing_Default_Case_in_Switch__basic_01_good();

void CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_01_bad();
void CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_01_good();

void CWE480_Use_of_Incorrect_Operator__basic_01_bad();
void CWE480_Use_of_Incorrect_Operator__basic_01_good();

void CWE481_Assigning_Instead_of_Comparing__basic_01_bad();
void CWE481_Assigning_Instead_of_Comparing__basic_01_good();

void CWE482_Comparing_Instead_of_Assigning__basic_01_bad();
void CWE482_Comparing_Instead_of_Assigning__basic_01_good();

void CWE483_Incorrect_Block_Delimitation__if_without_braces_multiple_lines_01_bad();
void CWE483_Incorrect_Block_Delimitation__if_without_braces_multiple_lines_01_good();

void CWE484_Omitted_Break_Statement_in_Switch__basic_01_bad();
void CWE484_Omitted_Break_Statement_in_Switch__basic_01_good();

void CWE546_Suspicious_Comment__BUG_01_bad();
void CWE546_Suspicious_Comment__BUG_01_good();

void CWE561_Dead_Code__return_before_code_01_bad();
void CWE561_Dead_Code__return_before_code_01_good();

void CWE562_Return_of_Stack_Variable_Address__return_buf_01_bad();
void CWE562_Return_of_Stack_Variable_Address__return_buf_01_good();

void CWE563_Unused_Variable__unused_global_value_01_bad();
void CWE563_Unused_Variable__unused_global_value_01_good();

void CWE570_Expression_Always_False__global_01_bad();
void CWE570_Expression_Always_False__global_01_good();

void CWE571_Expression_Always_True__global_01_bad();
void CWE571_Expression_Always_True__global_01_good();

void CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_01_bad();
void CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_01_good();

void CWE605_Multiple_Binds_Same_Port__basic_01_bad();
void CWE605_Multiple_Binds_Same_Port__basic_01_good();

void CWE606_Unchecked_Loop_Condition__char_console_01_bad();
void CWE606_Unchecked_Loop_Condition__char_console_01_good();

void CWE617_Reachable_Assertion__connect_socket_01_bad();
void CWE617_Reachable_Assertion__connect_socket_01_good();

void CWE665_Improper_Initialization__char_cat_01_bad();
void CWE665_Improper_Initialization__char_cat_01_good();

void CWE666_Operation_on_Resource_in_Wrong_Phase_of_Lifetime__accept_bind_listen_01_bad();
void CWE666_Operation_on_Resource_in_Wrong_Phase_of_Lifetime__accept_bind_listen_01_good();

void CWE667_Improper_Locking__basic_01_bad();
void CWE667_Improper_Locking__basic_01_good();

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_01_bad();
void CWE674_Uncontrolled_Recursion__infinite_recursive_call_01_good();

void CWE675_Duplicate_Operations_on_Resource__fopen_01_bad();
void CWE675_Duplicate_Operations_on_Resource__fopen_01_good();

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_connect_socket_01_bad();
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_connect_socket_01_good();

void CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_01_bad();
void CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_01_good();

void CWE685_Function_Call_With_Incorrect_Number_of_Arguments__basic_01_bad();
void CWE685_Function_Call_With_Incorrect_Number_of_Arguments__basic_01_good();

void CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_01_bad();
void CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_01_good();

void CWE690_NULL_Deref_From_Return__char_calloc_01_bad();
void CWE690_NULL_Deref_From_Return__char_calloc_01_good();

void CWE758_Undefined_Behavior__char_alloca_use_01_bad();
void CWE758_Undefined_Behavior__char_alloca_use_01_good();

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_connect_socket_01_bad();
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_connect_socket_01_good();

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_01_bad();
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_01_good();

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_01_bad();
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_01_good();

void CWE78_OS_Command_Injection__char_connect_socket_execl_01_bad();
void CWE78_OS_Command_Injection__char_connect_socket_execl_01_good();

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_01_bad();
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_connect_socket_01_good();

void CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_01_bad();
void CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_01_good();

void CWE835_Infinite_Loop__do_01_bad();
void CWE835_Infinite_Loop__do_01_good();

void CWE843_Type_Confusion__char_01_bad();
void CWE843_Type_Confusion__char_01_good();

#endif //  _TESTCASES_H
