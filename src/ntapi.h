// routine.c
// project sdk library
//
// Copyright (c) 2020-2024 Henry++

#pragma once

//
// Libraries
//

#pragma comment(lib, "ntdll.lib")

//
// Calling convention
//

#if defined(_WIN64)
#define FASTCALL
#else
#define FASTCALL __fastcall
#endif // _WIN64

//
// Errors
//

#if !defined(NT_FACILITY_MASK)
#define NT_FACILITY_MASK 0xFFF
#endif // !NT_FACILITY_MASK

#if !defined(NT_FACILITY_SHIFT)
#define NT_FACILITY_SHIFT 16
#endif // !NT_FACILITY_SHIFT

#if !defined(NT_FACILITY)
#define NT_FACILITY(Status) ((((ULONG)(Status)) >> NT_FACILITY_SHIFT) & NT_FACILITY_MASK)
#endif // !NT_FACILITY

#if !defined(NT_NTWIN32)
#define NT_NTWIN32(Status) (NT_FACILITY(Status) == FACILITY_NTWIN32)
#endif // !NT_NTWIN32

#if !defined(WIN32_FROM_NTSTATUS)
#define WIN32_FROM_NTSTATUS(Status) (((ULONG)(Status)) & 0xFFFF)
#endif // !WIN32_FROM_NTSTATUS

//
// Memory
//

#define PTR_ADD_OFFSET(pointer, offset) ((PVOID)((ULONG_PTR)(pointer) + (ULONG_PTR)(offset)))
#define PTR_SUB_OFFSET(pointer, offset) ((PVOID)((ULONG_PTR)(pointer) - (ULONG_PTR)(offset)))

#define ALIGN_UP_BY(address, align) (((ULONG_PTR)(address) + (align) - 1) & ~((align) - 1))
#define ALIGN_UP_POINTER_BY(pointer, align) ((PVOID)ALIGN_UP_BY(pointer, align))
#define ALIGN_UP(address, type) ALIGN_UP_BY(address, sizeof(type))
#define ALIGN_UP_POINTER(pointer, type) ((PVOID)ALIGN_UP(pointer, type))
#define ALIGN_DOWN_BY(address, align) ((ULONG_PTR)(address) & ~((ULONG_PTR)(align) - 1))
#define ALIGN_DOWN_POINTER_BY(pointer, align) ((PVOID)ALIGN_DOWN_BY(pointer, align))
#define ALIGN_DOWN(address, type) ALIGN_DOWN_BY(address, sizeof(type))
#define ALIGN_DOWN_POINTER(pointer, type) ((PVOID)ALIGN_DOWN(pointer, type))

#define IS_ALIGNED(pointer, align) ((((ULONG_PTR)(pointer)) & ((align) - 1)) == 0)

#define PAGE_SIZE 0x1000

//
// Icons (shell32)
//

#if !defined(SIH_APPLICATION)
#define SIH_APPLICATION 32512
#endif // !SIH_APPLICATION

#if !defined(SIH_ERROR)
#define SIH_ERROR 32513
#endif // !SIH_ERROR

#if !defined(SIH_QUESTION)
#define SIH_QUESTION 32514
#endif // !SIH_QUESTION

#if !defined(SIH_EXCLAMATION)
#define SIH_EXCLAMATION 32515
#endif // !SIH_EXCLAMATION

#if !defined(SIH_INFORMATION)
#define SIH_INFORMATION 32516
#endif // !SIH_INFORMATION

#if !defined(SIH_WINLOGO)
#define SIH_WINLOGO 32517
#endif // !SIH_WINLOGO

#if !defined(SIH_SHIELD)
#define SIH_SHIELD 32518
#endif // !SIH_SHIELD

//
// Path separator
//

#if !defined(OBJ_NAME_PATH_SEPARATOR)
#define OBJ_NAME_PATH_SEPARATOR L'\\'
#endif // !OBJ_NAME_PATH_SEPARATOR

#if !defined(OBJ_NAME_ALTPATH_SEPARATOR)
#define OBJ_NAME_ALTPATH_SEPARATOR L'/'
#endif // !OBJ_NAME_ALTPATH_SEPARATOR

//
// Undocumented codes
//

#if !defined(LVM_RESETEMPTYTEXT)
#define LVM_RESETEMPTYTEXT (LVM_FIRST + 84)
#endif // !LVM_RESETEMPTYTEXT

#if !defined(WM_COPYGLOBALDATA)
#define WM_COPYGLOBALDATA 0x0049
#endif // !WM_COPYGLOBALDATA

//
// Privileges
//

#define SE_MIN_WELL_KNOWN_PRIVILEGE (2L)
#define SE_CREATE_TOKEN_PRIVILEGE (2L)
#define SE_ASSIGNPRIMARYTOKEN_PRIVILEGE (3L)
#define SE_LOCK_MEMORY_PRIVILEGE (4L)
#define SE_INCREASE_QUOTA_PRIVILEGE (5L)
#define SE_MACHINE_ACCOUNT_PRIVILEGE (6L)
#define SE_TCB_PRIVILEGE (7L)
#define SE_SECURITY_PRIVILEGE (8L)
#define SE_TAKE_OWNERSHIP_PRIVILEGE (9L)
#define SE_LOAD_DRIVER_PRIVILEGE (10L)
#define SE_SYSTEM_PROFILE_PRIVILEGE (11L)
#define SE_SYSTEMTIME_PRIVILEGE (12L)
#define SE_PROF_SINGLE_PROCESS_PRIVILEGE (13L)
#define SE_INC_BASE_PRIORITY_PRIVILEGE (14L)
#define SE_CREATE_PAGEFILE_PRIVILEGE (15L)
#define SE_CREATE_PERMANENT_PRIVILEGE (16L)
#define SE_BACKUP_PRIVILEGE (17L)
#define SE_RESTORE_PRIVILEGE (18L)
#define SE_SHUTDOWN_PRIVILEGE (19L)
#define SE_DEBUG_PRIVILEGE (20L)
#define SE_AUDIT_PRIVILEGE (21L)
#define SE_SYSTEM_ENVIRONMENT_PRIVILEGE (22L)
#define SE_CHANGE_NOTIFY_PRIVILEGE (23L)
#define SE_REMOTE_SHUTDOWN_PRIVILEGE (24L)
#define SE_UNDOCK_PRIVILEGE (25L)
#define SE_SYNC_AGENT_PRIVILEGE (26L)
#define SE_ENABLE_DELEGATION_PRIVILEGE (27L)
#define SE_MANAGE_VOLUME_PRIVILEGE (28L)
#define SE_IMPERSONATE_PRIVILEGE (29L)
#define SE_CREATE_GLOBAL_PRIVILEGE (30L)
#define SE_TRUSTED_CREDMAN_ACCESS_PRIVILEGE (31L)
#define SE_RELABEL_PRIVILEGE (32L)
#define SE_INC_WORKING_SET_PRIVILEGE (33L)
#define SE_TIME_ZONE_PRIVILEGE (34L)
#define SE_CREATE_SYMBOLIC_LINK_PRIVILEGE (35L)
#define SE_DELEGATE_SESSION_USER_IMPERSONATE_PRIVILEGE (36L)
#define SE_MAX_WELL_KNOWN_PRIVILEGE SE_DELEGATE_SESSION_USER_IMPERSONATE_PRIVILEGE

// Create disposition

#define FILE_SUPERSEDE 0x00000000
#define FILE_OPEN 0x00000001
#define FILE_CREATE 0x00000002
#define FILE_OPEN_IF 0x00000003
#define FILE_OVERWRITE 0x00000004
#define FILE_OVERWRITE_IF 0x00000005
#define FILE_MAXIMUM_DISPOSITION 0x00000005

//
// Create/open flags
//

#define FILE_DIRECTORY_FILE 0x00000001
#define FILE_WRITE_THROUGH 0x00000002
#define FILE_SEQUENTIAL_ONLY 0x00000004
#define FILE_NO_INTERMEDIATE_BUFFERING 0x00000008

#define FILE_SYNCHRONOUS_IO_ALERT 0x00000010
#define FILE_SYNCHRONOUS_IO_NONALERT 0x00000020
#define FILE_NON_DIRECTORY_FILE 0x00000040
#define FILE_CREATE_TREE_CONNECTION 0x00000080

#define FILE_COMPLETE_IF_OPLOCKED 0x00000100
#define FILE_NO_EA_KNOWLEDGE 0x00000200
#define FILE_OPEN_REMOTE_INSTANCE 0x00000400
#define FILE_RANDOM_ACCESS 0x00000800

#define FILE_DELETE_ON_CLOSE 0x00001000
#define FILE_OPEN_BY_FILE_ID 0x00002000
#define FILE_OPEN_FOR_BACKUP_INTENT 0x00004000
#define FILE_NO_COMPRESSION 0x00008000

// win7+
#define FILE_OPEN_REQUIRING_OPLOCK 0x00010000
#define FILE_DISALLOW_EXCLUSIVE 0x00020000

// win8+
#define FILE_SESSION_AWARE 0x00040000

#define FILE_RESERVE_OPFILTER 0x00100000
#define FILE_OPEN_REPARSE_POINT 0x00200000
#define FILE_OPEN_NO_RECALL 0x00400000
#define FILE_OPEN_FOR_FREE_SPACE_QUERY 0x00800000

//
// Process parameters flags
//

#define RTL_USER_PROCESS_PARAMETERS_NORMALIZED 0x01
#define RTL_USER_PROCESS_PARAMETERS_PROFILE_USER 0x02
#define RTL_USER_PROCESS_PARAMETERS_PROFILE_KERNEL 0x04
#define RTL_USER_PROCESS_PARAMETERS_PROFILE_SERVER 0x08
#define RTL_USER_PROCESS_PARAMETERS_RESERVE_1MB 0x20
#define RTL_USER_PROCESS_PARAMETERS_RESERVE_16MB 0x40
#define RTL_USER_PROCESS_PARAMETERS_CASE_SENSITIVE 0x80
#define RTL_USER_PROCESS_PARAMETERS_DISABLE_HEAP_DECOMMIT 0x100
#define RTL_USER_PROCESS_PARAMETERS_DLL_REDIRECTION_LOCAL 0x1000
#define RTL_USER_PROCESS_PARAMETERS_APP_MANIFEST_PRESENT 0x2000
#define RTL_USER_PROCESS_PARAMETERS_IMAGE_KEY_MISSING 0x4000
#define RTL_USER_PROCESS_PARAMETERS_NX_OPTIN 0x20000

//
// Process flags
//

#define PROCESS_CREATE_FLAGS_BREAKAWAY 0x00000001 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_NO_DEBUG_INHERIT 0x00000002 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_INHERIT_HANDLES 0x00000004 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_OVERRIDE_ADDRESS_SPACE 0x00000008 // NtCreateProcessEx only
#define PROCESS_CREATE_FLAGS_LARGE_PAGES 0x00000010 // NtCreateProcessEx only, requires SeLockMemory
#define PROCESS_CREATE_FLAGS_LARGE_PAGE_SYSTEM_DLL 0x00000020 // NtCreateProcessEx only, requires SeLockMemory
#define PROCESS_CREATE_FLAGS_PROTECTED_PROCESS 0x00000040 // NtCreateUserProcess only
#define PROCESS_CREATE_FLAGS_CREATE_SESSION 0x00000080 // NtCreateProcessEx & NtCreateUserProcess, requires SeLoadDriver
#define PROCESS_CREATE_FLAGS_INHERIT_FROM_PARENT 0x00000100 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_SUSPENDED 0x00000200 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_FORCE_BREAKAWAY 0x00000400 // NtCreateProcessEx & NtCreateUserProcess, requires SeTcb
#define PROCESS_CREATE_FLAGS_MINIMAL_PROCESS 0x00000800 // NtCreateProcessEx only
#define PROCESS_CREATE_FLAGS_RELEASE_SECTION 0x00001000 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_CLONE_MINIMAL 0x00002000 // NtCreateProcessEx only
#define PROCESS_CREATE_FLAGS_CLONE_MINIMAL_REDUCED_COMMIT 0x00004000 //
#define PROCESS_CREATE_FLAGS_AUXILIARY_PROCESS 0x00008000 // NtCreateProcessEx & NtCreateUserProcess, requires SeTcb
#define PROCESS_CREATE_FLAGS_CREATE_STORE 0x00020000 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_USE_PROTECTED_ENVIRONMENT 0x00040000 // NtCreateProcessEx & NtCreateUserProcess

//
// Thread flags
//

#define THREAD_CREATE_FLAGS_NONE 0x00000000
#define THREAD_CREATE_FLAGS_CREATE_SUSPENDED 0x00000001 // NtCreateUserProcess & NtCreateThreadEx
#define THREAD_CREATE_FLAGS_SKIP_THREAD_ATTACH 0x00000002 // NtCreateThreadEx only
#define THREAD_CREATE_FLAGS_HIDE_FROM_DEBUGGER 0x00000004 // NtCreateThreadEx only
#define THREAD_CREATE_FLAGS_LOADER_WORKER 0x00000010 // NtCreateThreadEx only
#define THREAD_CREATE_FLAGS_SKIP_LOADER_INIT 0x00000020 // NtCreateThreadEx only
#define THREAD_CREATE_FLAGS_BYPASS_PROCESS_FREEZE 0x00000040 // NtCreateThreadEx only

// This isn't in NT, but it's useful.
typedef struct DECLSPEC_ALIGN (MEMORY_ALLOCATION_ALIGNMENT) _QUAD_PTR
{
	ULONG_PTR DoNotUseThisField1;
	ULONG_PTR DoNotUseThisField2;
} QUAD_PTR, *PQUAD_PTR;

typedef ULONG LOGICAL;
typedef ULONG *PLOGICAL;

#include <pshpack1.h>
typedef struct _DLGTEMPLATEEX
{
	WORD dlgVer;
	WORD signature;
	ULONG helpID;
	ULONG exStyle;
	ULONG style;
	WORD cdit;
	SHORT x;
	SHORT y;
	SHORT cx;
	SHORT cy;

	// Everything else in this structure is variable length,
	// and therefore must be determined dynamically

	// sz_Or_Ord menu;			// name or ordinal of a menu resource
	// sz_Or_Ord windowClass;	// name or ordinal of a window class
	// WCHAR title[titleLen];	// title string of the dialog box
	// SHORT pointsize;			// only if DS_SETFONT is set
	// SHORT weight;			// only if DS_SETFONT is set
	// SHORT bItalic;			// only if DS_SETFONT is set
	// WCHAR font[fontLen];		// typeface name, if DS_SETFONT is set
} DLGTEMPLATEEX, *LPDLGTEMPLATEEX;

typedef struct _DLGITEMTEMPLATEEX
{
	ULONG helpID;
	ULONG exStyle;
	ULONG style;
	SHORT x;
	SHORT y;
	SHORT cx;
	SHORT cy;
	ULONG id;

	// Everything else in this structure is variable length,
	// and therefore must be determined dynamically

	// sz_Or_Ord windowClass;	// name or ordinal of a window class
	// sz_Or_Ord title;			// title string or ordinal of a resource
	// WORD extraCount;			// bytes following creation data
} DLGITEMTEMPLATEEX, *LPDLGITEMTEMPLATEEX;
#include <poppack.h>

//
// types
//

typedef UCHAR KIRQL, *PKIRQL;
typedef LONG KPRIORITY;
typedef USHORT RTL_ATOM, *PRTL_ATOM;

//
// enums
//

// rev
// private
// source:http://www.microsoft.com/whdc/system/Sysinternals/MoreThan64proc.mspx
typedef enum _SYSTEM_INFORMATION_CLASS
{
	SystemBasicInformation, // q: SYSTEM_BASIC_INFORMATION
	SystemProcessorInformation, // q: SYSTEM_PROCESSOR_INFORMATION
	SystemPerformanceInformation, // q: SYSTEM_PERFORMANCE_INFORMATION
	SystemTimeOfDayInformation, // q: SYSTEM_TIMEOFDAY_INFORMATION
	SystemPathInformation, // not implemented
	SystemProcessInformation, // q: SYSTEM_PROCESS_INFORMATION
	SystemCallCountInformation, // q: SYSTEM_CALL_COUNT_INFORMATION
	SystemDeviceInformation, // q: SYSTEM_DEVICE_INFORMATION
	SystemProcessorPerformanceInformation, // q: SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION (EX in: USHORT ProcessorGroup)
	SystemFlagsInformation, // q: SYSTEM_FLAGS_INFORMATION
	SystemCallTimeInformation, // not implemented // SYSTEM_CALL_TIME_INFORMATION // 10
	SystemModuleInformation, // q: RTL_PROCESS_MODULES
	SystemLocksInformation, // q: RTL_PROCESS_LOCKS
	SystemStackTraceInformation, // q: RTL_PROCESS_BACKTRACES
	SystemPagedPoolInformation, // not implemented
	SystemNonPagedPoolInformation, // not implemented
	SystemHandleInformation, // q: SYSTEM_HANDLE_INFORMATION
	SystemObjectInformation, // q: SYSTEM_OBJECTTYPE_INFORMATION mixed with SYSTEM_OBJECT_INFORMATION
	SystemPageFileInformation, // q: SYSTEM_PAGEFILE_INFORMATION
	SystemVdmInstemulInformation, // q: SYSTEM_VDM_INSTEMUL_INFO
	SystemVdmBopInformation, // not implemented // 20
	SystemFileCacheInformation, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypeSystemCache)
	SystemPoolTagInformation, // q: SYSTEM_POOLTAG_INFORMATION
	SystemInterruptInformation, // q: SYSTEM_INTERRUPT_INFORMATION (EX in: USHORT ProcessorGroup)
	SystemDpcBehaviorInformation, // q: SYSTEM_DPC_BEHAVIOR_INFORMATION; s: SYSTEM_DPC_BEHAVIOR_INFORMATION (requires SeLoadDriverPrivilege)
	SystemFullMemoryInformation, // not implemented // SYSTEM_MEMORY_USAGE_INFORMATION
	SystemLoadGdiDriverInformation, // s (kernel-mode only)
	SystemUnloadGdiDriverInformation, // s (kernel-mode only)
	SystemTimeAdjustmentInformation, // q: SYSTEM_QUERY_TIME_ADJUST_INFORMATION; s: SYSTEM_SET_TIME_ADJUST_INFORMATION (requires SeSystemtimePrivilege)
	SystemSummaryMemoryInformation, // not implemented // SYSTEM_MEMORY_USAGE_INFORMATION
	SystemMirrorMemoryInformation, // s (requires license value "Kernel-MemoryMirroringSupported") (requires SeShutdownPrivilege) // 30
	SystemPerformanceTraceInformation, // q; s: (type depends on EVENT_TRACE_INFORMATION_CLASS)
	SystemObsolete0, // not implemented
	SystemExceptionInformation, // q: SYSTEM_EXCEPTION_INFORMATION
	SystemCrashDumpStateInformation, // s: SYSTEM_CRASH_DUMP_STATE_INFORMATION (requires SeDebugPrivilege)
	SystemKernelDebuggerInformation, // q: SYSTEM_KERNEL_DEBUGGER_INFORMATION
	SystemContextSwitchInformation, // q: SYSTEM_CONTEXT_SWITCH_INFORMATION
	SystemRegistryQuotaInformation, // q: SYSTEM_REGISTRY_QUOTA_INFORMATION; s (requires SeIncreaseQuotaPrivilege)
	SystemExtendServiceTableInformation, // s (requires SeLoadDriverPrivilege) // loads win32k only
	SystemPrioritySeperation, // s (requires SeTcbPrivilege)
	SystemVerifierAddDriverInformation, // s (requires SeDebugPrivilege) // 40
	SystemVerifierRemoveDriverInformation, // s (requires SeDebugPrivilege)
	SystemProcessorIdleInformation, // q: SYSTEM_PROCESSOR_IDLE_INFORMATION (EX in: USHORT ProcessorGroup)
	SystemLegacyDriverInformation, // q: SYSTEM_LEGACY_DRIVER_INFORMATION
	SystemCurrentTimeZoneInformation, // q; s: RTL_TIME_ZONE_INFORMATION
	SystemLookasideInformation, // q: SYSTEM_LOOKASIDE_INFORMATION
	SystemTimeSlipNotification, // s: HANDLE (NtCreateEvent) (requires SeSystemtimePrivilege)
	SystemSessionCreate, // not implemented
	SystemSessionDetach, // not implemented
	SystemSessionInformation, // not implemented (SYSTEM_SESSION_INFORMATION)
	SystemRangeStartInformation, // q: SYSTEM_RANGE_START_INFORMATION // 50
	SystemVerifierInformation, // q: SYSTEM_VERIFIER_INFORMATION; s (requires SeDebugPrivilege)
	SystemVerifierThunkExtend, // s (kernel-mode only)
	SystemSessionProcessInformation, // q: SYSTEM_SESSION_PROCESS_INFORMATION
	SystemLoadGdiDriverInSystemSpace, // s: SYSTEM_GDI_DRIVER_INFORMATION (kernel-mode only) (same as SystemLoadGdiDriverInformation)
	SystemNumaProcessorMap, // q: SYSTEM_NUMA_INFORMATION
	SystemPrefetcherInformation, // q; s: PREFETCHER_INFORMATION // PfSnQueryPrefetcherInformation
	SystemExtendedProcessInformation, // q: SYSTEM_PROCESS_INFORMATION
	SystemRecommendedSharedDataAlignment, // q: ULONG // KeGetRecommendedSharedDataAlignment
	SystemComPlusPackage, // q; s: ULONG
	SystemNumaAvailableMemory, // q: SYSTEM_NUMA_INFORMATION // 60
	SystemProcessorPowerInformation, // q: SYSTEM_PROCESSOR_POWER_INFORMATION (EX in: USHORT ProcessorGroup)
	SystemEmulationBasicInformation, // q: SYSTEM_BASIC_INFORMATION
	SystemEmulationProcessorInformation, // q: SYSTEM_PROCESSOR_INFORMATION
	SystemExtendedHandleInformation, // q: SYSTEM_HANDLE_INFORMATION_EX
	SystemLostDelayedWriteInformation, // q: ULONG
	SystemBigPoolInformation, // q: SYSTEM_BIGPOOL_INFORMATION
	SystemSessionPoolTagInformation, // q: SYSTEM_SESSION_POOLTAG_INFORMATION
	SystemSessionMappedViewInformation, // q: SYSTEM_SESSION_MAPPED_VIEW_INFORMATION
	SystemHotpatchInformation, // q; s: SYSTEM_HOTPATCH_CODE_INFORMATION
	SystemObjectSecurityMode, // q: ULONG // 70
	SystemWatchdogTimerHandler, // s: SYSTEM_WATCHDOG_HANDLER_INFORMATION // (kernel-mode only)
	SystemWatchdogTimerInformation, // q: SYSTEM_WATCHDOG_TIMER_INFORMATION // (kernel-mode only)
	SystemLogicalProcessorInformation, // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION (EX in: USHORT ProcessorGroup)
	SystemWow64SharedInformationObsolete, // not implemented
	SystemRegisterFirmwareTableInformationHandler, // s: SYSTEM_FIRMWARE_TABLE_HANDLER // (kernel-mode only)
	SystemFirmwareTableInformation, // SYSTEM_FIRMWARE_TABLE_INFORMATION
	SystemModuleInformationEx, // q: RTL_PROCESS_MODULE_INFORMATION_EX
	SystemVerifierTriageInformation, // not implemented
	SystemSuperfetchInformation, // q; s: SUPERFETCH_INFORMATION // PfQuerySuperfetchInformation
	SystemMemoryListInformation, // q: SYSTEM_MEMORY_LIST_INFORMATION; s: SYSTEM_MEMORY_LIST_COMMAND (requires SeProfileSingleProcessPrivilege) // 80
	SystemFileCacheInformationEx, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (same as SystemFileCacheInformation)
	SystemThreadPriorityClientIdInformation, // s: SYSTEM_THREAD_CID_PRIORITY_INFORMATION (requires SeIncreaseBasePriorityPrivilege)
	SystemProcessorIdleCycleTimeInformation, // q: SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION[] (EX in: USHORT ProcessorGroup)
	SystemVerifierCancellationInformation, // SYSTEM_VERIFIER_CANCELLATION_INFORMATION // name:wow64:whNT32QuerySystemVerifierCancellationInformation
	SystemProcessorPowerInformationEx, // not implemented
	SystemRefTraceInformation, // q; s: SYSTEM_REF_TRACE_INFORMATION // ObQueryRefTraceInformation
	SystemSpecialPoolInformation, // q; s: SYSTEM_SPECIAL_POOL_INFORMATION (requires SeDebugPrivilege) // MmSpecialPoolTag, then MmSpecialPoolCatchOverruns != 0
	SystemProcessIdInformation, // q: SYSTEM_PROCESS_ID_INFORMATION
	SystemErrorPortInformation, // s (requires SeTcbPrivilege)
	SystemBootEnvironmentInformation, // q: SYSTEM_BOOT_ENVIRONMENT_INFORMATION // 90
	SystemHypervisorInformation, // q: SYSTEM_HYPERVISOR_QUERY_INFORMATION
	SystemVerifierInformationEx, // q; s: SYSTEM_VERIFIER_INFORMATION_EX
	SystemTimeZoneInformation, // q; s: RTL_TIME_ZONE_INFORMATION (requires SeTimeZonePrivilege)
	SystemImageFileExecutionOptionsInformation, // s: SYSTEM_IMAGE_FILE_EXECUTION_OPTIONS_INFORMATION (requires SeTcbPrivilege)
	SystemCoverageInformation, // q: COVERAGE_MODULES s: COVERAGE_MODULE_REQUEST // ExpCovQueryInformation (requires SeDebugPrivilege)
	SystemPrefetchPatchInformation, // SYSTEM_PREFETCH_PATCH_INFORMATION
	SystemVerifierFaultsInformation, // s: SYSTEM_VERIFIER_FAULTS_INFORMATION (requires SeDebugPrivilege)
	SystemSystemPartitionInformation, // q: SYSTEM_SYSTEM_PARTITION_INFORMATION
	SystemSystemDiskInformation, // q: SYSTEM_SYSTEM_DISK_INFORMATION
	SystemProcessorPerformanceDistribution, // q: SYSTEM_PROCESSOR_PERFORMANCE_DISTRIBUTION (EX in: USHORT ProcessorGroup) // 100
	SystemNumaProximityNodeInformation, // q; s: SYSTEM_NUMA_PROXIMITY_MAP
	SystemDynamicTimeZoneInformation, // q; s: RTL_DYNAMIC_TIME_ZONE_INFORMATION (requires SeTimeZonePrivilege)
	SystemCodeIntegrityInformation, // q: SYSTEM_CODEINTEGRITY_INFORMATION // SeCodeIntegrityQueryInformation
	SystemProcessorMicrocodeUpdateInformation, // s: SYSTEM_PROCESSOR_MICROCODE_UPDATE_INFORMATION
	SystemProcessorBrandString, // q: CHAR[] // HaliQuerySystemInformation -> HalpGetProcessorBrandString, info class 23
	SystemVirtualAddressInformation, // q: SYSTEM_VA_LIST_INFORMATION[]; s: SYSTEM_VA_LIST_INFORMATION[] (requires SeIncreaseQuotaPrivilege) // MmQuerySystemVaInformation
	SystemLogicalProcessorAndGroupInformation, // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX (EX in: LOGICAL_PROCESSOR_RELATIONSHIP RelationshipType) // since WIN7 // KeQueryLogicalProcessorRelationship
	SystemProcessorCycleTimeInformation, // q: SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION[] (EX in: USHORT ProcessorGroup)
	SystemStoreInformation, // q; s: SYSTEM_STORE_INFORMATION (requires SeProfileSingleProcessPrivilege) // SmQueryStoreInformation
	SystemRegistryAppendString, // s: SYSTEM_REGISTRY_APPEND_STRING_PARAMETERS // 110
	SystemAitSamplingValue, // s: ULONG (requires SeProfileSingleProcessPrivilege)
	SystemVhdBootInformation, // q: SYSTEM_VHD_BOOT_INFORMATION
	SystemCpuQuotaInformation, // q; s: PS_CPU_QUOTA_QUERY_INFORMATION
	SystemNativeBasicInformation, // q: SYSTEM_BASIC_INFORMATION
	SystemErrorPortTimeouts, // SYSTEM_ERROR_PORT_TIMEOUTS
	SystemLowPriorityIoInformation, // q: SYSTEM_LOW_PRIORITY_IO_INFORMATION
	SystemTpmBootEntropyInformation, // q: TPM_BOOT_ENTROPY_NT_RESULT // ExQueryTpmBootEntropyInformation
	SystemVerifierCountersInformation, // q: SYSTEM_VERIFIER_COUNTERS_INFORMATION
	SystemPagedPoolInformationEx, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypePagedPool)
	SystemSystemPtesInformationEx, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypeSystemPtes) // 120
	SystemNodeDistanceInformation, // q: USHORT[4*NumaNodes] // (EX in: USHORT NodeNumber)
	SystemAcpiAuditInformation, // q: SYSTEM_ACPI_AUDIT_INFORMATION // HaliQuerySystemInformation -> HalpAuditQueryResults, info class 26
	SystemBasicPerformanceInformation, // q: SYSTEM_BASIC_PERFORMANCE_INFORMATION // name:wow64:whNtQuerySystemInformation_SystemBasicPerformanceInformation
	SystemQueryPerformanceCounterInformation, // q: SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION // since WIN7 SP1
	SystemSessionBigPoolInformation, // q: SYSTEM_SESSION_POOLTAG_INFORMATION // since WIN8
	SystemBootGraphicsInformation, // q; s: SYSTEM_BOOT_GRAPHICS_INFORMATION (kernel-mode only)
	SystemScrubPhysicalMemoryInformation, // q; s: MEMORY_SCRUB_INFORMATION
	SystemBadPageInformation,
	SystemProcessorProfileControlArea, // q; s: SYSTEM_PROCESSOR_PROFILE_CONTROL_AREA
	SystemCombinePhysicalMemoryInformation, // s: MEMORY_COMBINE_INFORMATION, MEMORY_COMBINE_INFORMATION_EX, MEMORY_COMBINE_INFORMATION_EX2 // 130
	SystemEntropyInterruptTimingInformation, // q; s: SYSTEM_ENTROPY_TIMING_INFORMATION
	SystemConsoleInformation, // q: SYSTEM_CONSOLE_INFORMATION
	SystemPlatformBinaryInformation, // q: SYSTEM_PLATFORM_BINARY_INFORMATION (requires SeTcbPrivilege)
	SystemPolicyInformation, // q: SYSTEM_POLICY_INFORMATION
	SystemHypervisorProcessorCountInformation, // q: SYSTEM_HYPERVISOR_PROCESSOR_COUNT_INFORMATION
	SystemDeviceDataInformation, // q: SYSTEM_DEVICE_DATA_INFORMATION
	SystemDeviceDataEnumerationInformation, // q: SYSTEM_DEVICE_DATA_INFORMATION
	SystemMemoryTopologyInformation, // q: SYSTEM_MEMORY_TOPOLOGY_INFORMATION
	SystemMemoryChannelInformation, // q: SYSTEM_MEMORY_CHANNEL_INFORMATION
	SystemBootLogoInformation, // q: SYSTEM_BOOT_LOGO_INFORMATION // 140
	SystemProcessorPerformanceInformationEx, // q: SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION_EX // (EX in: USHORT ProcessorGroup) // since WINBLUE
	SystemCriticalProcessErrorLogInformation,
	SystemSecureBootPolicyInformation, // q: SYSTEM_SECUREBOOT_POLICY_INFORMATION
	SystemPageFileInformationEx, // q: SYSTEM_PAGEFILE_INFORMATION_EX
	SystemSecureBootInformation, // q: SYSTEM_SECUREBOOT_INFORMATION
	SystemEntropyInterruptTimingRawInformation,
	SystemPortableWorkspaceEfiLauncherInformation, // q: SYSTEM_PORTABLE_WORKSPACE_EFI_LAUNCHER_INFORMATION
	SystemFullProcessInformation, // q: SYSTEM_PROCESS_INFORMATION with SYSTEM_PROCESS_INFORMATION_EXTENSION (requires admin)
	SystemKernelDebuggerInformationEx, // q: SYSTEM_KERNEL_DEBUGGER_INFORMATION_EX
	SystemBootMetadataInformation, // 150
	SystemSoftRebootInformation, // q: ULONG
	SystemElamCertificateInformation, // s: SYSTEM_ELAM_CERTIFICATE_INFORMATION
	SystemOfflineDumpConfigInformation, // q: OFFLINE_CRASHDUMP_CONFIGURATION_TABLE_V2
	SystemProcessorFeaturesInformation, // q: SYSTEM_PROCESSOR_FEATURES_INFORMATION
	SystemRegistryReconciliationInformation, // s: NULL (requires admin) (flushes registry hives)
	SystemEdidInformation, // q: SYSTEM_EDID_INFORMATION
	SystemManufacturingInformation, // q: SYSTEM_MANUFACTURING_INFORMATION // since THRESHOLD
	SystemEnergyEstimationConfigInformation, // q: SYSTEM_ENERGY_ESTIMATION_CONFIG_INFORMATION
	SystemHypervisorDetailInformation, // q: SYSTEM_HYPERVISOR_DETAIL_INFORMATION
	SystemProcessorCycleStatsInformation, // q: SYSTEM_PROCESSOR_CYCLE_STATS_INFORMATION (EX in: USHORT ProcessorGroup) // 160
	SystemVmGenerationCountInformation,
	SystemTrustedPlatformModuleInformation, // q: SYSTEM_TPM_INFORMATION
	SystemKernelDebuggerFlags, // SYSTEM_KERNEL_DEBUGGER_FLAGS
	SystemCodeIntegrityPolicyInformation, // q: SYSTEM_CODEINTEGRITYPOLICY_INFORMATION
	SystemIsolatedUserModeInformation, // q: SYSTEM_ISOLATED_USER_MODE_INFORMATION
	SystemHardwareSecurityTestInterfaceResultsInformation,
	SystemSingleModuleInformation, // q: SYSTEM_SINGLE_MODULE_INFORMATION
	SystemAllowedCpuSetsInformation,
	SystemVsmProtectionInformation, // q: SYSTEM_VSM_PROTECTION_INFORMATION (previously SystemDmaProtectionInformation)
	SystemInterruptCpuSetsInformation, // q: SYSTEM_INTERRUPT_CPU_SET_INFORMATION // 170
	SystemSecureBootPolicyFullInformation, // q: SYSTEM_SECUREBOOT_POLICY_FULL_INFORMATION
	SystemCodeIntegrityPolicyFullInformation,
	SystemAffinitizedInterruptProcessorInformation, // (requires SeIncreaseBasePriorityPrivilege)
	SystemRootSiloInformation, // q: SYSTEM_ROOT_SILO_INFORMATION
	SystemCpuSetInformation, // q: SYSTEM_CPU_SET_INFORMATION // since THRESHOLD2
	SystemCpuSetTagInformation, // q: SYSTEM_CPU_SET_TAG_INFORMATION
	SystemWin32WerStartCallout,
	SystemSecureKernelProfileInformation, // q: SYSTEM_SECURE_KERNEL_HYPERGUARD_PROFILE_INFORMATION
	SystemCodeIntegrityPlatformManifestInformation, // q: SYSTEM_SECUREBOOT_PLATFORM_MANIFEST_INFORMATION // since REDSTONE
	SystemInterruptSteeringInformation, // SYSTEM_INTERRUPT_STEERING_INFORMATION_INPUT // 180
	SystemSupportedProcessorArchitectures, // p: in opt: HANDLE, out: SYSTEM_SUPPORTED_PROCESSOR_ARCHITECTURES_INFORMATION[] // NtQuerySystemInformationEx
	SystemMemoryUsageInformation, // q: SYSTEM_MEMORY_USAGE_INFORMATION
	SystemCodeIntegrityCertificateInformation, // q: SYSTEM_CODEINTEGRITY_CERTIFICATE_INFORMATION
	SystemPhysicalMemoryInformation, // q: SYSTEM_PHYSICAL_MEMORY_INFORMATION // since REDSTONE2
	SystemControlFlowTransition,
	SystemKernelDebuggingAllowed, // s: ULONG
	SystemActivityModerationExeState, // SYSTEM_ACTIVITY_MODERATION_EXE_STATE
	SystemActivityModerationUserSettings, // SYSTEM_ACTIVITY_MODERATION_USER_SETTINGS
	SystemCodeIntegrityPoliciesFullInformation,
	SystemCodeIntegrityUnlockInformation, // SYSTEM_CODEINTEGRITY_UNLOCK_INFORMATION // 190
	SystemIntegrityQuotaInformation,
	SystemFlushInformation, // q: SYSTEM_FLUSH_INFORMATION
	SystemProcessorIdleMaskInformation, // q: ULONG_PTR[ActiveGroupCount] // since REDSTONE3
	SystemSecureDumpEncryptionInformation,
	SystemWriteConstraintInformation, // SYSTEM_WRITE_CONSTRAINT_INFORMATION
	SystemKernelVaShadowInformation, // SYSTEM_KERNEL_VA_SHADOW_INFORMATION
	SystemHypervisorSharedPageInformation, // SYSTEM_HYPERVISOR_SHARED_PAGE_INFORMATION // since REDSTONE4
	SystemFirmwareBootPerformanceInformation,
	SystemCodeIntegrityVerificationInformation, // SYSTEM_CODEINTEGRITYVERIFICATION_INFORMATION
	SystemFirmwarePartitionInformation, // SYSTEM_FIRMWARE_PARTITION_INFORMATION // 200
	SystemSpeculationControlInformation, // SYSTEM_SPECULATION_CONTROL_INFORMATION // (CVE-2017-5715) REDSTONE3 and above.
	SystemDmaGuardPolicyInformation, // SYSTEM_DMA_GUARD_POLICY_INFORMATION
	SystemEnclaveLaunchControlInformation, // SYSTEM_ENCLAVE_LAUNCH_CONTROL_INFORMATION
	SystemWorkloadAllowedCpuSetsInformation, // SYSTEM_WORKLOAD_ALLOWED_CPU_SET_INFORMATION // since REDSTONE5
	SystemCodeIntegrityUnlockModeInformation,
	SystemLeapSecondInformation, // SYSTEM_LEAP_SECOND_INFORMATION
	SystemFlags2Information, // q: SYSTEM_FLAGS_INFORMATION
	SystemSecurityModelInformation, // SYSTEM_SECURITY_MODEL_INFORMATION // since 19H1
	SystemCodeIntegritySyntheticCacheInformation,
	SystemFeatureConfigurationInformation, // SYSTEM_FEATURE_CONFIGURATION_INFORMATION // since 20H1 // 210
	SystemFeatureConfigurationSectionInformation, // SYSTEM_FEATURE_CONFIGURATION_SECTIONS_INFORMATION
	SystemFeatureUsageSubscriptionInformation, // SYSTEM_FEATURE_USAGE_SUBSCRIPTION_DETAILS
	SystemSecureSpeculationControlInformation, // SECURE_SPECULATION_CONTROL_INFORMATION
	SystemSpacesBootInformation, // since 20H2
	SystemFwRamdiskInformation, // SYSTEM_FIRMWARE_RAMDISK_INFORMATION
	SystemWheaIpmiHardwareInformation,
	SystemDifSetRuleClassInformation,
	SystemDifClearRuleClassInformation,
	SystemDifApplyPluginVerificationOnDriver,
	SystemDifRemovePluginVerificationOnDriver, // 220
	SystemShadowStackInformation, // SYSTEM_SHADOW_STACK_INFORMATION
	SystemBuildVersionInformation, // SYSTEM_BUILD_VERSION_INFORMATION
	SystemPoolLimitInformation, // SYSTEM_POOL_LIMIT_INFORMATION
	SystemCodeIntegrityAddDynamicStore,
	SystemCodeIntegrityClearDynamicStores,
	SystemDifPoolTrackingInformation,
	SystemPoolZeroingInformation, // SYSTEM_POOL_ZEROING_INFORMATION
	SystemDpcWatchdogInformation,
	SystemDpcWatchdogInformation2,
	SystemSupportedProcessorArchitectures2, // q: in opt: HANDLE, out: SYSTEM_SUPPORTED_PROCESSOR_ARCHITECTURES_INFORMATION[] // NtQuerySystemInformationEx // 230
	SystemSingleProcessorRelationshipInformation, // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX // (EX in: PROCESSOR_NUMBER Processor)
	SystemXfgCheckFailureInformation,
	SystemIommuStateInformation, // SYSTEM_IOMMU_STATE_INFORMATION // since 22H1
	SystemHypervisorMinrootInformation, // SYSTEM_HYPERVISOR_MINROOT_INFORMATION
	SystemHypervisorBootPagesInformation, // SYSTEM_HYPERVISOR_BOOT_PAGES_INFORMATION
	SystemPointerAuthInformation, // SYSTEM_POINTER_AUTH_INFORMATION
	SystemSecureKernelDebuggerInformation,
	SystemOriginalImageFeatureInformation,
	MaxSystemInfoClass
} SYSTEM_INFORMATION_CLASS;

typedef enum _FILE_INFORMATION_CLASS
{
	FileDirectoryInformation = 1, // FILE_DIRECTORY_INFORMATION
	FileFullDirectoryInformation, // FILE_FULL_DIR_INFORMATION
	FileBothDirectoryInformation, // FILE_BOTH_DIR_INFORMATION
	FileBasicInformation, // FILE_BASIC_INFORMATION
	FileStandardInformation, // FILE_STANDARD_INFORMATION
	FileInternalInformation, // FILE_INTERNAL_INFORMATION
	FileEaInformation, // FILE_EA_INFORMATION
	FileAccessInformation, // FILE_ACCESS_INFORMATION
	FileNameInformation, // FILE_NAME_INFORMATION
	FileRenameInformation, // FILE_RENAME_INFORMATION // 10
	FileLinkInformation, // FILE_LINK_INFORMATION
	FileNamesInformation, // FILE_NAMES_INFORMATION
	FileDispositionInformation, // FILE_DISPOSITION_INFORMATION
	FilePositionInformation, // FILE_POSITION_INFORMATION
	FileFullEaInformation, // FILE_FULL_EA_INFORMATION
	FileModeInformation, // FILE_MODE_INFORMATION
	FileAlignmentInformation, // FILE_ALIGNMENT_INFORMATION
	FileAllInformation, // FILE_ALL_INFORMATION
	FileAllocationInformation, // FILE_ALLOCATION_INFORMATION
	FileEndOfFileInformation, // FILE_END_OF_FILE_INFORMATION // 20
	FileAlternateNameInformation, // FILE_NAME_INFORMATION
	FileStreamInformation, // FILE_STREAM_INFORMATION
	FilePipeInformation, // FILE_PIPE_INFORMATION
	FilePipeLocalInformation, // FILE_PIPE_LOCAL_INFORMATION
	FilePipeRemoteInformation, // FILE_PIPE_REMOTE_INFORMATION
	FileMailslotQueryInformation, // FILE_MAILSLOT_QUERY_INFORMATION
	FileMailslotSetInformation, // FILE_MAILSLOT_SET_INFORMATION
	FileCompressionInformation, // FILE_COMPRESSION_INFORMATION
	FileObjectIdInformation, // FILE_OBJECTID_INFORMATION
	FileCompletionInformation, // FILE_COMPLETION_INFORMATION // 30
	FileMoveClusterInformation, // FILE_MOVE_CLUSTER_INFORMATION
	FileQuotaInformation, // FILE_QUOTA_INFORMATION
	FileReparsePointInformation, // FILE_REPARSE_POINT_INFORMATION
	FileNetworkOpenInformation, // FILE_NETWORK_OPEN_INFORMATION
	FileAttributeTagInformation, // FILE_ATTRIBUTE_TAG_INFORMATION
	FileTrackingInformation, // FILE_TRACKING_INFORMATION
	FileIdBothDirectoryInformation, // FILE_ID_BOTH_DIR_INFORMATION
	FileIdFullDirectoryInformation, // FILE_ID_FULL_DIR_INFORMATION
	FileValidDataLengthInformation, // FILE_VALID_DATA_LENGTH_INFORMATION
	FileShortNameInformation, // FILE_NAME_INFORMATION // 40
	FileIoCompletionNotificationInformation, // FILE_IO_COMPLETION_NOTIFICATION_INFORMATION // since VISTA
	FileIoStatusBlockRangeInformation, // FILE_IOSTATUSBLOCK_RANGE_INFORMATION
	FileIoPriorityHintInformation, // FILE_IO_PRIORITY_HINT_INFORMATION, FILE_IO_PRIORITY_HINT_INFORMATION_EX
	FileSfioReserveInformation, // FILE_SFIO_RESERVE_INFORMATION
	FileSfioVolumeInformation, // FILE_SFIO_VOLUME_INFORMATION
	FileHardLinkInformation, // FILE_LINKS_INFORMATION
	FileProcessIdsUsingFileInformation, // FILE_PROCESS_IDS_USING_FILE_INFORMATION
	FileNormalizedNameInformation, // FILE_NAME_INFORMATION
	FileNetworkPhysicalNameInformation, // FILE_NETWORK_PHYSICAL_NAME_INFORMATION
	FileIdGlobalTxDirectoryInformation, // FILE_ID_GLOBAL_TX_DIR_INFORMATION // since WIN7 // 50
	FileIsRemoteDeviceInformation, // FILE_IS_REMOTE_DEVICE_INFORMATION
	FileUnusedInformation,
	FileNumaNodeInformation, // FILE_NUMA_NODE_INFORMATION
	FileStandardLinkInformation, // FILE_STANDARD_LINK_INFORMATION
	FileRemoteProtocolInformation, // FILE_REMOTE_PROTOCOL_INFORMATION
	FileRenameInformationBypassAccessCheck, // (kernel-mode only); FILE_RENAME_INFORMATION // since WIN8
	FileLinkInformationBypassAccessCheck, // (kernel-mode only); FILE_LINK_INFORMATION
	FileVolumeNameInformation, // FILE_VOLUME_NAME_INFORMATION
	FileIdInformation, // FILE_ID_INFORMATION
	FileIdExtdDirectoryInformation, // FILE_ID_EXTD_DIR_INFORMATION // 60
	FileReplaceCompletionInformation, // FILE_COMPLETION_INFORMATION // since WINBLUE
	FileHardLinkFullIdInformation, // FILE_LINK_ENTRY_FULL_ID_INFORMATION // FILE_LINKS_FULL_ID_INFORMATION
	FileIdExtdBothDirectoryInformation, // FILE_ID_EXTD_BOTH_DIR_INFORMATION // since THRESHOLD
	FileDispositionInformationEx, // FILE_DISPOSITION_INFO_EX // since REDSTONE
	FileRenameInformationEx, // FILE_RENAME_INFORMATION_EX
	FileRenameInformationExBypassAccessCheck, // (kernel-mode only); FILE_RENAME_INFORMATION_EX
	FileDesiredStorageClassInformation, // FILE_DESIRED_STORAGE_CLASS_INFORMATION // since REDSTONE2
	FileStatInformation, // FILE_STAT_INFORMATION
	FileMemoryPartitionInformation, // FILE_MEMORY_PARTITION_INFORMATION // since REDSTONE3
	FileStatLxInformation, // FILE_STAT_LX_INFORMATION // since REDSTONE4 // 70
	FileCaseSensitiveInformation, // FILE_CASE_SENSITIVE_INFORMATION
	FileLinkInformationEx, // FILE_LINK_INFORMATION_EX // since REDSTONE5
	FileLinkInformationExBypassAccessCheck, // (kernel-mode only); FILE_LINK_INFORMATION_EX
	FileStorageReserveIdInformation, // FILE_SET_STORAGE_RESERVE_ID_INFORMATION
	FileCaseSensitiveInformationForceAccessCheck, // FILE_CASE_SENSITIVE_INFORMATION
	FileKnownFolderInformation, // FILE_KNOWN_FOLDER_INFORMATION // since WIN11
	FileMaximumInformation
} FILE_INFORMATION_CLASS, *PFILE_INFORMATION_CLASS;

typedef enum _PROCESSINFOCLASS
{
	ProcessBasicInformation, // q: PROCESS_BASIC_INFORMATION, PROCESS_EXTENDED_BASIC_INFORMATION
	ProcessQuotaLimits, // qs: QUOTA_LIMITS, QUOTA_LIMITS_EX
	ProcessIoCounters, // q: IO_COUNTERS
	ProcessVmCounters, // q: VM_COUNTERS, VM_COUNTERS_EX, VM_COUNTERS_EX2
	ProcessTimes, // q: KERNEL_USER_TIMES
	ProcessBasePriority, // s: KPRIORITY
	ProcessRaisePriority, // s: ULONG
	ProcessDebugPort, // q: HANDLE
	ProcessExceptionPort, // s: PROCESS_EXCEPTION_PORT
	ProcessAccessToken, // s: PROCESS_ACCESS_TOKEN
	ProcessLdtInformation, // qs: PROCESS_LDT_INFORMATION // 10
	ProcessLdtSize, // s: PROCESS_LDT_SIZE
	ProcessDefaultHardErrorMode, // qs: ULONG
	ProcessIoPortHandlers, // (kernel-mode only) // PROCESS_IO_PORT_HANDLER_INFORMATION
	ProcessPooledUsageAndLimits, // q: POOLED_USAGE_AND_LIMITS
	ProcessWorkingSetWatch, // q: PROCESS_WS_WATCH_INFORMATION[]; s: void
	ProcessUserModeIOPL, // qs: ULONG (requires SeTcbPrivilege)
	ProcessEnableAlignmentFaultFixup, // s: BOOLEAN
	ProcessPriorityClass, // qs: PROCESS_PRIORITY_CLASS
	ProcessWx86Information, // qs: ULONG (requires SeTcbPrivilege) (VdmAllowed)
	ProcessHandleCount, // q: ULONG, PROCESS_HANDLE_INFORMATION // 20
	ProcessAffinityMask, // qs: KAFFINITY, qs: GROUP_AFFINITY
	ProcessPriorityBoost, // qs: ULONG
	ProcessDeviceMap, // qs: PROCESS_DEVICEMAP_INFORMATION, PROCESS_DEVICEMAP_INFORMATION_EX
	ProcessSessionInformation, // q: PROCESS_SESSION_INFORMATION
	ProcessForegroundInformation, // s: PROCESS_FOREGROUND_BACKGROUND
	ProcessWow64Information, // q: ULONG_PTR
	ProcessImageFileName, // q: UNICODE_STRING
	ProcessLUIDDeviceMapsEnabled, // q: ULONG
	ProcessBreakOnTermination, // qs: ULONG
	ProcessDebugObjectHandle, // q: HANDLE // 30
	ProcessDebugFlags, // qs: ULONG
	ProcessHandleTracing, // q: PROCESS_HANDLE_TRACING_QUERY; s: size 0 disables, otherwise enables
	ProcessIoPriority, // qs: IO_PRIORITY_HINT
	ProcessExecuteFlags, // qs: ULONG
	ProcessTlsInformation, // PROCESS_TLS_INFORMATION // ProcessResourceManagement
	ProcessCookie, // q: ULONG
	ProcessImageInformation, // q: SECTION_IMAGE_INFORMATION
	ProcessCycleTime, // q: PROCESS_CYCLE_TIME_INFORMATION // since VISTA
	ProcessPagePriority, // q: PAGE_PRIORITY_INFORMATION
	ProcessInstrumentationCallback, // s: PVOID or PROCESS_INSTRUMENTATION_CALLBACK_INFORMATION // 40
	ProcessThreadStackAllocation, // s: PROCESS_STACK_ALLOCATION_INFORMATION, PROCESS_STACK_ALLOCATION_INFORMATION_EX
	ProcessWorkingSetWatchEx, // q: PROCESS_WS_WATCH_INFORMATION_EX[]
	ProcessImageFileNameWin32, // q: UNICODE_STRING
	ProcessImageFileMapping, // q: HANDLE (input)
	ProcessAffinityUpdateMode, // qs: PROCESS_AFFINITY_UPDATE_MODE
	ProcessMemoryAllocationMode, // qs: PROCESS_MEMORY_ALLOCATION_MODE
	ProcessGroupInformation, // q: USHORT[]
	ProcessTokenVirtualizationEnabled, // s: ULONG
	ProcessConsoleHostProcess, // q: ULONG_PTR // ProcessOwnerInformation
	ProcessWindowInformation, // q: PROCESS_WINDOW_INFORMATION // 50
	ProcessHandleInformation, // q: PROCESS_HANDLE_SNAPSHOT_INFORMATION // since WIN8
	ProcessMitigationPolicy, // s: PROCESS_MITIGATION_POLICY_INFORMATION
	ProcessDynamicFunctionTableInformation,
	ProcessHandleCheckingMode, // qs: ULONG; s: 0 disables, otherwise enables
	ProcessKeepAliveCount, // q: PROCESS_KEEPALIVE_COUNT_INFORMATION
	ProcessRevokeFileHandles, // s: PROCESS_REVOKE_FILE_HANDLES_INFORMATION
	ProcessWorkingSetControl, // s: PROCESS_WORKING_SET_CONTROL
	ProcessHandleTable, // q: ULONG[] // since WINBLUE
	ProcessCheckStackExtentsMode, // qs: ULONG // KPROCESS->CheckStackExtents (CFG)
	ProcessCommandLineInformation, // q: UNICODE_STRING // 60
	ProcessProtectionInformation, // q: PS_PROTECTION
	ProcessMemoryExhaustion, // PROCESS_MEMORY_EXHAUSTION_INFO // since THRESHOLD
	ProcessFaultInformation, // PROCESS_FAULT_INFORMATION
	ProcessTelemetryIdInformation, // q: PROCESS_TELEMETRY_ID_INFORMATION
	ProcessCommitReleaseInformation, // PROCESS_COMMIT_RELEASE_INFORMATION
	ProcessDefaultCpuSetsInformation, // SYSTEM_CPU_SET_INFORMATION[5]
	ProcessAllowedCpuSetsInformation, // SYSTEM_CPU_SET_INFORMATION[5]
	ProcessSubsystemProcess,
	ProcessJobMemoryInformation, // q: PROCESS_JOB_MEMORY_INFO
	ProcessInPrivate, // s: void // ETW // since THRESHOLD2 // 70
	ProcessRaiseUMExceptionOnInvalidHandleClose, // qs: ULONG; s: 0 disables, otherwise enables
	ProcessIumChallengeResponse,
	ProcessChildProcessInformation, // q: PROCESS_CHILD_PROCESS_INFORMATION
	ProcessHighGraphicsPriorityInformation, // qs: BOOLEAN (requires SeTcbPrivilege)
	ProcessSubsystemInformation, // q: SUBSYSTEM_INFORMATION_TYPE // since REDSTONE2
	ProcessEnergyValues, // q: PROCESS_ENERGY_VALUES, PROCESS_EXTENDED_ENERGY_VALUES
	ProcessPowerThrottlingState, // qs: POWER_THROTTLING_PROCESS_STATE
	ProcessReserved3Information, // ProcessActivityThrottlePolicy // PROCESS_ACTIVITY_THROTTLE_POLICY
	ProcessWin32kSyscallFilterInformation, // q: WIN32K_SYSCALL_FILTER
	ProcessDisableSystemAllowedCpuSets, // 80
	ProcessWakeInformation, // PROCESS_WAKE_INFORMATION
	ProcessEnergyTrackingState, // PROCESS_ENERGY_TRACKING_STATE
	ProcessManageWritesToExecutableMemory, // MANAGE_WRITES_TO_EXECUTABLE_MEMORY // since REDSTONE3
	ProcessCaptureTrustletLiveDump,
	ProcessTelemetryCoverage,
	ProcessEnclaveInformation,
	ProcessEnableReadWriteVmLogging, // PROCESS_READWRITEVM_LOGGING_INFORMATION
	ProcessUptimeInformation, // q: PROCESS_UPTIME_INFORMATION
	ProcessImageSection, // q: HANDLE
	ProcessDebugAuthInformation, // since REDSTONE4 // 90
	ProcessSystemResourceManagement, // PROCESS_SYSTEM_RESOURCE_MANAGEMENT
	ProcessSequenceNumber, // q: ULONG64
	ProcessLoaderDetour, // since REDSTONE5
	ProcessSecurityDomainInformation, // PROCESS_SECURITY_DOMAIN_INFORMATION
	ProcessCombineSecurityDomainsInformation, // PROCESS_COMBINE_SECURITY_DOMAINS_INFORMATION
	ProcessEnableLogging, // PROCESS_LOGGING_INFORMATION
	ProcessLeapSecondInformation, // PROCESS_LEAP_SECOND_INFORMATION
	ProcessFiberShadowStackAllocation, // PROCESS_FIBER_SHADOW_STACK_ALLOCATION_INFORMATION // since 19H1
	ProcessFreeFiberShadowStackAllocation, // PROCESS_FREE_FIBER_SHADOW_STACK_ALLOCATION_INFORMATION
	ProcessAltSystemCallInformation, // qs: BOOLEAN (kernel-mode only) // INT2E // since 20H1 // 100
	ProcessDynamicEHContinuationTargets, // PROCESS_DYNAMIC_EH_CONTINUATION_TARGETS_INFORMATION
	ProcessDynamicEnforcedCetCompatibleRanges, // PROCESS_DYNAMIC_ENFORCED_ADDRESS_RANGE_INFORMATION // since 20H2
	ProcessCreateStateChange, // since WIN11
	ProcessApplyStateChange,
	ProcessEnableOptionalXStateFeatures,
	ProcessAltPrefetchParam, // since 22H1
	ProcessAssignCpuPartitions,
	ProcessPriorityClassEx,
	ProcessMembershipInformation,
	ProcessEffectiveIoPriority,
	ProcessEffectivePagePriority,
	MaxProcessInfoClass
} PROCESSINFOCLASS;

typedef enum _THREADINFOCLASS
{
	ThreadBasicInformation, // q: THREAD_BASIC_INFORMATION
	ThreadTimes, // q: KERNEL_USER_TIMES
	ThreadPriority, // s: KPRIORITY (requires SeIncreaseBasePriorityPrivilege)
	ThreadBasePriority, // s: KPRIORITY
	ThreadAffinityMask, // s: KAFFINITY
	ThreadImpersonationToken, // s: HANDLE
	ThreadDescriptorTableEntry, // q: DESCRIPTOR_TABLE_ENTRY (or WOW64_DESCRIPTOR_TABLE_ENTRY)
	ThreadEnableAlignmentFaultFixup, // s: BOOLEAN
	ThreadEventPair,
	ThreadQuerySetWin32StartAddress, // q: ULONG_PTR
	ThreadZeroTlsCell, // s: ULONG // TlsIndex // 10
	ThreadPerformanceCount, // q: LARGE_INTEGER
	ThreadAmILastThread, // q: ULONG
	ThreadIdealProcessor, // s: ULONG
	ThreadPriorityBoost, // qs: ULONG
	ThreadSetTlsArrayAddress, // s: ULONG_PTR
	ThreadIsIoPending, // q: ULONG
	ThreadHideFromDebugger, // q: BOOLEAN; s: void
	ThreadBreakOnTermination, // qs: ULONG
	ThreadSwitchLegacyState, // s: void // NtCurrentThread // NPX/FPU
	ThreadIsTerminated, // q: ULONG // 20
	ThreadLastSystemCall, // q: THREAD_LAST_SYSCALL_INFORMATION
	ThreadIoPriority, // qs: IO_PRIORITY_HINT (requires SeIncreaseBasePriorityPrivilege)
	ThreadCycleTime, // q: THREAD_CYCLE_TIME_INFORMATION
	ThreadPagePriority, // q: ULONG
	ThreadActualBasePriority, // s: LONG (requires SeIncreaseBasePriorityPrivilege)
	ThreadTebInformation, // q: THREAD_TEB_INFORMATION (requires THREAD_GET_CONTEXT + THREAD_SET_CONTEXT)
	ThreadCSwitchMon,
	ThreadCSwitchPmu,
	ThreadWow64Context, // qs: WOW64_CONTEXT
	ThreadGroupInformation, // qs: GROUP_AFFINITY // 30
	ThreadUmsInformation, // q: THREAD_UMS_INFORMATION
	ThreadCounterProfiling, // q: BOOLEAN; s: THREAD_PROFILING_INFORMATION?
	ThreadIdealProcessorEx, // qs: PROCESSOR_NUMBER; s: previous PROCESSOR_NUMBER on return
	ThreadCpuAccountingInformation, // q: BOOLEAN; s: HANDLE (NtOpenSession) // NtCurrentThread // since WIN8
	ThreadSuspendCount, // q: ULONG // since WINBLUE
	ThreadHeterogeneousCpuPolicy, // q: KHETERO_CPU_POLICY // since THRESHOLD
	ThreadContainerId, // q: GUID
	ThreadNameInformation, // qs: THREAD_NAME_INFORMATION
	ThreadSelectedCpuSets,
	ThreadSystemThreadInformation, // q: SYSTEM_THREAD_INFORMATION // 40
	ThreadActualGroupAffinity, // q: GROUP_AFFINITY // since THRESHOLD2
	ThreadDynamicCodePolicyInfo, // q: ULONG; s: ULONG (NtCurrentThread)
	ThreadExplicitCaseSensitivity, // qs: ULONG; s: 0 disables, otherwise enables
	ThreadWorkOnBehalfTicket, // RTL_WORK_ON_BEHALF_TICKET_EX
	ThreadSubsystemInformation, // q: SUBSYSTEM_INFORMATION_TYPE // since REDSTONE2
	ThreadDbgkWerReportActive, // s: ULONG; s: 0 disables, otherwise enables
	ThreadAttachContainer, // s: HANDLE (job object) // NtCurrentThread
	ThreadManageWritesToExecutableMemory, // MANAGE_WRITES_TO_EXECUTABLE_MEMORY // since REDSTONE3
	ThreadPowerThrottlingState, // POWER_THROTTLING_THREAD_STATE
	ThreadWorkloadClass, // THREAD_WORKLOAD_CLASS // since REDSTONE5 // 50
	ThreadCreateStateChange, // since WIN11
	ThreadApplyStateChange,
	ThreadStrongerBadHandleChecks, // since 22H1
	ThreadEffectiveIoPriority,
	ThreadEffectivePagePriority,
	MaxThreadInfoClass
} THREADINFOCLASS;

typedef enum _MEMORY_INFORMATION_CLASS
{
	MemoryBasicInformation, // q: MEMORY_BASIC_INFORMATION
	MemoryWorkingSetInformation, // q: MEMORY_WORKING_SET_INFORMATION
	MemoryMappedFilenameInformation, // q: UNICODE_STRING
	MemoryRegionInformation, // q: MEMORY_REGION_INFORMATION
	MemoryWorkingSetExInformation, // q: MEMORY_WORKING_SET_EX_INFORMATION // since VISTA
	MemorySharedCommitInformation, // q: MEMORY_SHARED_COMMIT_INFORMATION // since WIN8
	MemoryImageInformation, // q: MEMORY_IMAGE_INFORMATION
	MemoryRegionInformationEx, // MEMORY_REGION_INFORMATION
	MemoryPrivilegedBasicInformation, // MEMORY_BASIC_INFORMATION
	MemoryEnclaveImageInformation, // MEMORY_ENCLAVE_IMAGE_INFORMATION // since REDSTONE3
	MemoryBasicInformationCapped, // 10
	MemoryPhysicalContiguityInformation, // MEMORY_PHYSICAL_CONTIGUITY_INFORMATION // since 20H1
	MemoryBadInformation, // since WIN11
	MemoryBadInformationAllProcesses, // since 22H1
	MaxMemoryInfoClass
} MEMORY_INFORMATION_CLASS;

typedef enum _KWAIT_REASON
{
	Executive,
	FreePage,
	PageIn,
	PoolAllocation,
	DelayExecution,
	Suspended,
	UserRequest,
	WrExecutive,
	WrFreePage,
	WrPageIn,
	WrPoolAllocation,
	WrDelayExecution,
	WrSuspended,
	WrUserRequest,
	WrEventPair,
	WrQueue,
	WrLpcReceive,
	WrLpcReply,
	WrVirtualMemory,
	WrPageOut,
	WrRendezvous,
	WrKeyedEvent,
	WrTerminated,
	WrProcessInSwap,
	WrCpuRateControl,
	WrCalloutStack,
	WrKernel,
	WrResource,
	WrPushLock,
	WrMutex,
	WrQuantumEnd,
	WrDispatchInt,
	WrPreempted,
	WrYieldExecution,
	WrFastMutex,
	WrGuardedMutex,
	WrRundown,
	WrAlertByThreadId,
	WrDeferredPreempt,
	WrPhysicalFault,
	WrIoRing,
	WrMdlCache,
	MaximumWaitReason
} KWAIT_REASON, *PKWAIT_REASON;

typedef enum _OBJECT_INFORMATION_CLASS
{
	ObjectBasicInformation, // q: OBJECT_BASIC_INFORMATION
	ObjectNameInformation, // q: OBJECT_NAME_INFORMATION
	ObjectTypeInformation, // q: OBJECT_TYPE_INFORMATION
	ObjectTypesInformation, // q: OBJECT_TYPES_INFORMATION
	ObjectHandleFlagInformation, // qs: OBJECT_HANDLE_FLAG_INFORMATION
	ObjectSessionInformation, // s: void // change object session // (requires SeTcbPrivilege)
	ObjectSessionObjectInformation, // s: void // change object session // (requires SeTcbPrivilege)
	MaxObjectInfoClass
} OBJECT_INFORMATION_CLASS;

typedef enum _KEY_INFORMATION_CLASS
{
	KeyBasicInformation, // KEY_BASIC_INFORMATION
	KeyNodeInformation, // KEY_NODE_INFORMATION
	KeyFullInformation, // KEY_FULL_INFORMATION
	KeyNameInformation, // KEY_NAME_INFORMATION
	KeyCachedInformation, // KEY_CACHED_INFORMATION
	KeyFlagsInformation, // KEY_FLAGS_INFORMATION
	KeyVirtualizationInformation, // KEY_VIRTUALIZATION_INFORMATION
	KeyHandleTagsInformation, // KEY_HANDLE_TAGS_INFORMATION
	KeyTrustInformation, // KEY_TRUST_INFORMATION
	KeyLayerInformation, // KEY_LAYER_INFORMATION
	MaxKeyInfoClass
} KEY_INFORMATION_CLASS;

typedef enum _KEY_SET_INFORMATION_CLASS
{
	KeyWriteTimeInformation, // KEY_WRITE_TIME_INFORMATION
	KeyWow64FlagsInformation, // KEY_WOW64_FLAGS_INFORMATION
	KeyControlFlagsInformation, // KEY_CONTROL_FLAGS_INFORMATION
	KeySetVirtualizationInformation, // KEY_SET_VIRTUALIZATION_INFORMATION
	KeySetDebugInformation,
	KeySetHandleTagsInformation, // KEY_HANDLE_TAGS_INFORMATION
	KeySetLayerInformation, // KEY_SET_LAYER_INFORMATION
	MaxKeySetInfoClass
} KEY_SET_INFORMATION_CLASS;

typedef enum _KEY_VALUE_INFORMATION_CLASS
{
	KeyValueBasicInformation, // KEY_VALUE_BASIC_INFORMATION
	KeyValueFullInformation, // KEY_VALUE_FULL_INFORMATION
	KeyValuePartialInformation, // KEY_VALUE_PARTIAL_INFORMATION
	KeyValueFullInformationAlign64,
	KeyValuePartialInformationAlign64, // KEY_VALUE_PARTIAL_INFORMATION_ALIGN64
	KeyValueLayerInformation, // KEY_VALUE_LAYER_INFORMATION
	MaxKeyValueInfoClass
} KEY_VALUE_INFORMATION_CLASS;

typedef enum _TAG_INFO_LEVEL
{
	TagInfoLevelNameFromTag = 1, // TAG_INFO_NAME_FROM_TAG
	TagInfoLevelNamesReferencingModule, // TAG_INFO_NAMES_REFERENCING_MODULE
	TagInfoLevelNameTagMapping, // TAG_INFO_NAME_TAG_MAPPING
	TagInfoLevelMax
} TAG_INFO_LEVEL, *PTAG_INFO_LEVEL;

// private
typedef enum _SYSTEM_MEMORY_LIST_COMMAND
{
	MemoryCaptureAccessedBits,
	MemoryCaptureAndResetAccessedBits,
	MemoryEmptyWorkingSets,
	MemoryFlushModifiedList,
	MemoryPurgeStandbyList,
	MemoryPurgeLowPriorityStandbyList,
	MemoryCommandMax
} SYSTEM_MEMORY_LIST_COMMAND;

typedef enum _KTHREAD_STATE
{
	Initialized,
	Ready,
	Running,
	Standby,
	Terminated,
	Waiting,
	Transition,
	DeferredReady,
	GateWaitObsolete,
	WaitingForProcessInSwap,
	MaximumThreadState
} KTHREAD_STATE, *PKTHREAD_STATE;

typedef enum _FSINFOCLASS
{
	FileFsVolumeInformation = 1, // q: FILE_FS_VOLUME_INFORMATION
	FileFsLabelInformation, // s: FILE_FS_LABEL_INFORMATION (requires FILE_WRITE_DATA to volume)
	FileFsSizeInformation, // q: FILE_FS_SIZE_INFORMATION
	FileFsDeviceInformation, // q: FILE_FS_DEVICE_INFORMATION
	FileFsAttributeInformation, // q: FILE_FS_ATTRIBUTE_INFORMATION
	FileFsControlInformation, // q, s: FILE_FS_CONTROL_INFORMATION (q: requires FILE_READ_DATA; s: requires FILE_WRITE_DATA to volume)
	FileFsFullSizeInformation, // q: FILE_FS_FULL_SIZE_INFORMATION
	FileFsObjectIdInformation, // q; s: FILE_FS_OBJECTID_INFORMATION (s: requires FILE_WRITE_DATA to volume)
	FileFsDriverPathInformation, // q: FILE_FS_DRIVER_PATH_INFORMATION
	FileFsVolumeFlagsInformation, // q; s: FILE_FS_VOLUME_FLAGS_INFORMATION (q: requires FILE_READ_ATTRIBUTES; s: requires FILE_WRITE_ATTRIBUTES to volume) // 10
	FileFsSectorSizeInformation, // q: FILE_FS_SECTOR_SIZE_INFORMATION // since WIN8
	FileFsDataCopyInformation, // q: FILE_FS_DATA_COPY_INFORMATION
	FileFsMetadataSizeInformation, // q: FILE_FS_METADATA_SIZE_INFORMATION // since THRESHOLD
	FileFsFullSizeInformationEx, // q: FILE_FS_FULL_SIZE_INFORMATION_EX // since REDSTONE5
	FileFsMaximumInformation
} FSINFOCLASS, *PFSINFOCLASS;

typedef enum _PreferredAppMode
{
	PreferredAppModeDisabled,
	PreferredAppModeDarkOnDark,
	PreferredAppModeDarkAlways
} PreferredAppMode;

//
// structs
//

typedef const UNICODE_STRING *PCUNICODE_STRING;

typedef struct _FILE_FS_SIZE_INFORMATION
{
	LARGE_INTEGER TotalAllocationUnits;
	LARGE_INTEGER AvailableAllocationUnits;
	ULONG SectorsPerAllocationUnit;
	ULONG BytesPerSector;
} FILE_FS_SIZE_INFORMATION, *PFILE_FS_SIZE_INFORMATION;

typedef struct _FILE_FS_VOLUME_INFORMATION
{
	LARGE_INTEGER VolumeCreationTime;
	ULONG VolumeSerialNumber;
	ULONG VolumeLabelLength;
	BOOLEAN SupportsObjects;
	_Field_size_bytes_ (VolumeLabelLength) WCHAR VolumeLabel[1];
} FILE_FS_VOLUME_INFORMATION, *PFILE_FS_VOLUME_INFORMATION;

typedef struct _FILE_FS_ATTRIBUTE_INFORMATION
{
	ULONG FileSystemAttributes;
	LONG MaximumComponentNameLength;
	ULONG FileSystemNameLength;
	_Field_size_bytes_ (FileSystemNameLength) WCHAR FileSystemName[1];
} FILE_FS_ATTRIBUTE_INFORMATION, *PFILE_FS_ATTRIBUTE_INFORMATION;

typedef struct _FILE_FS_DEVICE_INFORMATION
{
	ULONG DeviceType;
	ULONG Characteristics;
} FILE_FS_DEVICE_INFORMATION, *PFILE_FS_DEVICE_INFORMATION;

typedef struct _FILE_DIRECTORY_INFORMATION
{
	ULONG NextEntryOffset;
	ULONG FileIndex;
	LARGE_INTEGER CreationTime;
	LARGE_INTEGER LastAccessTime;
	LARGE_INTEGER LastWriteTime;
	LARGE_INTEGER ChangeTime;
	LARGE_INTEGER EndOfFile;
	LARGE_INTEGER AllocationSize;
	ULONG FileAttributes;
	ULONG FileNameLength;
	_Field_size_bytes_ (FileNameLength) WCHAR FileName[1];
} FILE_DIRECTORY_INFORMATION, *PFILE_DIRECTORY_INFORMATION;

typedef struct _FILE_NAMES_INFORMATION
{
	ULONG NextEntryOffset;
	ULONG FileIndex;
	ULONG FileNameLength;
	_Field_size_bytes_ (FileNameLength) WCHAR FileName[1];
} FILE_NAMES_INFORMATION, *PFILE_NAMES_INFORMATION;

typedef struct _FILE_DIRECTORY_NEXT_INFORMATION
{
	ULONG NextEntryOffset;
} FILE_DIRECTORY_NEXT_INFORMATION, *PFILE_DIRECTORY_NEXT_INFORMATION;

typedef struct _FILE_BASIC_INFORMATION
{
	LARGE_INTEGER CreationTime;
	LARGE_INTEGER LastAccessTime;
	LARGE_INTEGER LastWriteTime;
	LARGE_INTEGER ChangeTime;
	ULONG FileAttributes;
} FILE_BASIC_INFORMATION, *PFILE_BASIC_INFORMATION;

typedef struct _FILE_STANDARD_INFORMATION
{
	LARGE_INTEGER AllocationSize;
	LARGE_INTEGER EndOfFile;
	ULONG NumberOfLinks;
	BOOLEAN DeletePending;
	BOOLEAN Directory;
} FILE_STANDARD_INFORMATION, *PFILE_STANDARD_INFORMATION;

typedef struct _FILE_STANDARD_INFORMATION_EX
{
	LARGE_INTEGER AllocationSize;
	LARGE_INTEGER EndOfFile;
	ULONG NumberOfLinks;
	BOOLEAN DeletePending;
	BOOLEAN Directory;
	BOOLEAN AlternateStream;
	BOOLEAN MetadataAttribute;
} FILE_STANDARD_INFORMATION_EX, *PFILE_STANDARD_INFORMATION_EX;

typedef struct _FILE_INTERNAL_INFORMATION
{
	LARGE_INTEGER IndexNumber;
} FILE_INTERNAL_INFORMATION, *PFILE_INTERNAL_INFORMATION;

typedef struct _FILE_EA_INFORMATION
{
	ULONG EaSize;
} FILE_EA_INFORMATION, *PFILE_EA_INFORMATION;

typedef struct _FILE_ACCESS_INFORMATION
{
	ACCESS_MASK AccessFlags;
} FILE_ACCESS_INFORMATION, *PFILE_ACCESS_INFORMATION;

typedef struct _FILE_POSITION_INFORMATION
{
	LARGE_INTEGER CurrentByteOffset;
} FILE_POSITION_INFORMATION, *PFILE_POSITION_INFORMATION;

typedef struct _FILE_DISPOSITION_INFORMATION
{
	BOOLEAN FileDelete;
} FILE_DISPOSITION_INFORMATION, *PFILE_DISPOSITION_INFORMATION;

typedef struct _FILE_END_OF_FILE_INFORMATION
{
	LARGE_INTEGER EndOfFile;
} FILE_END_OF_FILE_INFORMATION, *PFILE_END_OF_FILE_INFORMATION;

typedef struct _CLIENT_ID
{
	HANDLE UniqueProcess;
	HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _SYSTEM_THREAD_INFORMATION
{
	LARGE_INTEGER KernelTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER CreateTime;
	ULONG WaitTime;
	PVOID StartAddress;
	CLIENT_ID ClientId;
	KPRIORITY Priority;
	KPRIORITY BasePriority;
	ULONG ContextSwitches;
	KTHREAD_STATE ThreadState;
	KWAIT_REASON WaitReason;
} SYSTEM_THREAD_INFORMATION, *PSYSTEM_THREAD_INFORMATION;

// Use with both ProcessPagePriority and ThreadPagePriority
typedef struct _PAGE_PRIORITY_INFORMATION
{
	ULONG PagePriority;
} PAGE_PRIORITY_INFORMATION, *PPAGE_PRIORITY_INFORMATION;

typedef struct _OBJECT_NAME_INFORMATION
{
	UNICODE_STRING Name;
} OBJECT_NAME_INFORMATION, *POBJECT_NAME_INFORMATION;

typedef struct _SYSTEM_PROCESS_INFORMATION
{
	ULONG NextEntryOffset;
	ULONG NumberOfThreads;
	LARGE_INTEGER WorkingSetPrivateSize; // since VISTA
	ULONG HardFaultCount; // since WIN7
	ULONG NumberOfThreadsHighWatermark; // since WIN7
	ULONG64 CycleTime; // since WIN7
	LARGE_INTEGER CreateTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER KernelTime;
	UNICODE_STRING ImageName;
	KPRIORITY BasePriority;
	HANDLE UniqueProcessId;
	HANDLE InheritedFromUniqueProcessId;
	ULONG HandleCount;
	ULONG SessionId;
	ULONG_PTR UniqueProcessKey; // since VISTA (requires SystemExtendedProcessInformation)
	ULONG_PTR PeakVirtualSize;
	ULONG_PTR VirtualSize;
	ULONG PageFaultCount;
	ULONG_PTR PeakWorkingSetSize;
	ULONG_PTR WorkingSetSize;
	ULONG_PTR QuotaPeakPagedPoolUsage;
	ULONG_PTR QuotaPagedPoolUsage;
	ULONG_PTR QuotaPeakNonPagedPoolUsage;
	ULONG_PTR QuotaNonPagedPoolUsage;
	ULONG_PTR PagefileUsage;
	ULONG_PTR PeakPagefileUsage;
	ULONG_PTR PrivatePageCount;
	LARGE_INTEGER ReadOperationCount;
	LARGE_INTEGER WriteOperationCount;
	LARGE_INTEGER OtherOperationCount;
	LARGE_INTEGER ReadTransferCount;
	LARGE_INTEGER WriteTransferCount;
	LARGE_INTEGER OtherTransferCount;
	SYSTEM_THREAD_INFORMATION Threads[1]; // SystemProcessInformation
	// SYSTEM_EXTENDED_THREAD_INFORMATION Threads[1]; // SystemExtendedProcessinformation
	// SYSTEM_EXTENDED_THREAD_INFORMATION + SYSTEM_PROCESS_INFORMATION_EXTENSION // SystemFullProcessInformation
} SYSTEM_PROCESS_INFORMATION, *PSYSTEM_PROCESS_INFORMATION;

typedef struct _SYSTEM_FILECACHE_INFORMATION
{
	ULONG_PTR CurrentSize;
	ULONG_PTR PeakSize;
	ULONG PageFaultCount;
	ULONG_PTR MinimumWorkingSet;
	ULONG_PTR MaximumWorkingSet;
	ULONG_PTR CurrentSizeIncludingTransitionInPages;
	ULONG_PTR PeakSizeIncludingTransitionInPages;
	ULONG TransitionRePurposeCount;
	ULONG Flags;
} SYSTEM_FILECACHE_INFORMATION, *PSYSTEM_FILECACHE_INFORMATION;

typedef struct _SYSTEM_BASIC_INFORMATION
{
	ULONG Reserved;
	ULONG TimerResolution;
	ULONG PageSize;
	ULONG NumberOfPhysicalPages;
	ULONG LowestPhysicalPageNumber;
	ULONG HighestPhysicalPageNumber;
	ULONG AllocationGranularity;
	ULONG_PTR MinimumUserModeAddress;
	ULONG_PTR MaximumUserModeAddress;
	KAFFINITY ActiveProcessorsAffinityMask;
	CCHAR NumberOfProcessors;
} SYSTEM_BASIC_INFORMATION, *PSYSTEM_BASIC_INFORMATION;

typedef struct _SYSTEM_PAGEFILE_INFORMATION
{
	ULONG NextEntryOffset;
	ULONG TotalSize;
	ULONG TotalInUse;
	ULONG PeakUsage;
	UNICODE_STRING PageFileName;
} SYSTEM_PAGEFILE_INFORMATION, *PSYSTEM_PAGEFILE_INFORMATION;

typedef struct _SYSTEM_PAGEFILE_INFORMATION_EX
{
	union
	{
		SYSTEM_PAGEFILE_INFORMATION Info;

		struct
		{
			ULONG NextEntryOffset;
			ULONG TotalSize;
			ULONG TotalInUse;
			ULONG PeakUsage;
			UNICODE_STRING PageFileName;
		};
	};

	ULONG MinimumSize;
	ULONG MaximumSize;
} SYSTEM_PAGEFILE_INFORMATION_EX, *PSYSTEM_PAGEFILE_INFORMATION_EX;

typedef struct _SYSTEM_PERFORMANCE_INFORMATION
{
	LARGE_INTEGER IdleProcessTime;
	LARGE_INTEGER IoReadTransferCount;
	LARGE_INTEGER IoWriteTransferCount;
	LARGE_INTEGER IoOtherTransferCount;
	ULONG IoReadOperationCount;
	ULONG IoWriteOperationCount;
	ULONG IoOtherOperationCount;
	ULONG AvailablePages;
	ULONG CommittedPages;
	ULONG CommitLimit;
	ULONG PeakCommitment;
	ULONG PageFaultCount;
	ULONG CopyOnWriteCount;
	ULONG TransitionCount;
	ULONG CacheTransitionCount;
	ULONG DemandZeroCount;
	ULONG PageReadCount;
	ULONG PageReadIoCount;
	ULONG CacheReadCount;
	ULONG CacheIoCount;
	ULONG DirtyPagesWriteCount;
	ULONG DirtyWriteIoCount;
	ULONG MappedPagesWriteCount;
	ULONG MappedWriteIoCount;
	ULONG PagedPoolPages;
	ULONG NonPagedPoolPages;
	ULONG PagedPoolAllocs;
	ULONG PagedPoolFrees;
	ULONG NonPagedPoolAllocs;
	ULONG NonPagedPoolFrees;
	ULONG FreeSystemPtes;
	ULONG ResidentSystemCodePage;
	ULONG TotalSystemDriverPages;
	ULONG TotalSystemCodePages;
	ULONG NonPagedPoolLookasideHits;
	ULONG PagedPoolLookasideHits;
	ULONG AvailablePagedPoolPages;
	ULONG ResidentSystemCachePage;
	ULONG ResidentPagedPoolPage;
	ULONG ResidentSystemDriverPage;
	ULONG CcFastReadNoWait;
	ULONG CcFastReadWait;
	ULONG CcFastReadResourceMiss;
	ULONG CcFastReadNotPossible;
	ULONG CcFastMdlReadNoWait;
	ULONG CcFastMdlReadWait;
	ULONG CcFastMdlReadResourceMiss;
	ULONG CcFastMdlReadNotPossible;
	ULONG CcMapDataNoWait;
	ULONG CcMapDataWait;
	ULONG CcMapDataNoWaitMiss;
	ULONG CcMapDataWaitMiss;
	ULONG CcPinMappedDataCount;
	ULONG CcPinReadNoWait;
	ULONG CcPinReadWait;
	ULONG CcPinReadNoWaitMiss;
	ULONG CcPinReadWaitMiss;
	ULONG CcCopyReadNoWait;
	ULONG CcCopyReadWait;
	ULONG CcCopyReadNoWaitMiss;
	ULONG CcCopyReadWaitMiss;
	ULONG CcMdlReadNoWait;
	ULONG CcMdlReadWait;
	ULONG CcMdlReadNoWaitMiss;
	ULONG CcMdlReadWaitMiss;
	ULONG CcReadAheadIos;
	ULONG CcLazyWriteIos;
	ULONG CcLazyWritePages;
	ULONG CcDataFlushes;
	ULONG CcDataPages;
	ULONG ContextSwitches;
	ULONG FirstLevelTbFills;
	ULONG SecondLevelTbFills;
	ULONG SystemCalls;
	ULONG64 CcTotalDirtyPages; // since THRESHOLD
	ULONG64 CcDirtyPageThreshold; // since THRESHOLD
	LONG64 ResidentAvailablePages; // since THRESHOLD
	ULONG64 SharedCommittedPages; // since THRESHOLD
} SYSTEM_PERFORMANCE_INFORMATION, *PSYSTEM_PERFORMANCE_INFORMATION;

// Can be used instead of SYSTEM_FILECACHE_INFORMATION
typedef struct _SYSTEM_BASIC_WORKING_SET_INFORMATION
{
	ULONG_PTR CurrentSize;
	ULONG_PTR PeakSize;
	ULONG PageFaultCount;
} SYSTEM_BASIC_WORKING_SET_INFORMATION, *PSYSTEM_BASIC_WORKING_SET_INFORMATION;

// private
typedef struct _MEMORY_COMBINE_INFORMATION
{
	HANDLE Handle;
	ULONG_PTR PagesCombined;
} MEMORY_COMBINE_INFORMATION, *PMEMORY_COMBINE_INFORMATION;

// rev
#define MEMORY_COMBINE_FLAGS_COMMON_PAGES_ONLY 0x4

// private
typedef struct _MEMORY_COMBINE_INFORMATION_EX
{
	HANDLE Handle;
	ULONG_PTR PagesCombined;
	ULONG Flags;
} MEMORY_COMBINE_INFORMATION_EX, *PMEMORY_COMBINE_INFORMATION_EX;

// private
typedef struct _MEMORY_COMBINE_INFORMATION_EX2
{
	HANDLE Handle;
	ULONG_PTR PagesCombined;
	ULONG Flags;
	HANDLE ProcessHandle;
} MEMORY_COMBINE_INFORMATION_EX2, *PMEMORY_COMBINE_INFORMATION_EX2;

// private
typedef struct _THREAD_NAME_INFORMATION
{
	UNICODE_STRING ThreadName;
} THREAD_NAME_INFORMATION, *PTHREAD_NAME_INFORMATION;

typedef struct _TAG_INFO_NAME_FROM_TAG
{
	struct
	{
		ULONG dwPid;
		ULONG dwTag;
	} InParams;

	struct
	{
		ULONG eTagType;
		PWSTR pszName;
	} OutParams;
} TAG_INFO_NAME_FROM_TAG, *PTAG_INFO_NAME_FROM_TAG;

#define PROCESS_PRIORITY_CLASS_UNKNOWN 0
#define PROCESS_PRIORITY_CLASS_IDLE 1
#define PROCESS_PRIORITY_CLASS_NORMAL 2
#define PROCESS_PRIORITY_CLASS_HIGH 3
#define PROCESS_PRIORITY_CLASS_REALTIME 4
#define PROCESS_PRIORITY_CLASS_BELOW_NORMAL 5
#define PROCESS_PRIORITY_CLASS_ABOVE_NORMAL 6

typedef struct _PROCESS_PRIORITY_CLASS
{
	BOOLEAN Foreground;
	UCHAR PriorityClass;
} PROCESS_PRIORITY_CLASS, *PPROCESS_PRIORITY_CLASS;

typedef struct _PROCESS_PRIORITY_CLASS_EX
{
	union
	{
		struct
		{
			USHORT ForegroundValid : 1;
			USHORT PriorityClassValid : 1;
		};

		USHORT AllFlags;
	};

	UCHAR PriorityClass;
	BOOLEAN Foreground;
} PROCESS_PRIORITY_CLASS_EX, *PPROCESS_PRIORITY_CLASS_EX;

typedef struct _PROCESS_MITIGATION_POLICY_INFORMATION
{
	PROCESS_MITIGATION_POLICY Policy;

	union
	{
		PROCESS_MITIGATION_ASLR_POLICY ASLRPolicy;
		PROCESS_MITIGATION_STRICT_HANDLE_CHECK_POLICY StrictHandleCheckPolicy;
		PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY SystemCallDisablePolicy;
		PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY ExtensionPointDisablePolicy;
		PROCESS_MITIGATION_DYNAMIC_CODE_POLICY DynamicCodePolicy;
		PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY ControlFlowGuardPolicy;
		PROCESS_MITIGATION_BINARY_SIGNATURE_POLICY SignaturePolicy;
		PROCESS_MITIGATION_FONT_DISABLE_POLICY FontDisablePolicy;
		PROCESS_MITIGATION_IMAGE_LOAD_POLICY ImageLoadPolicy;
		PROCESS_MITIGATION_SYSTEM_CALL_FILTER_POLICY SystemCallFilterPolicy;
		PROCESS_MITIGATION_PAYLOAD_RESTRICTION_POLICY PayloadRestrictionPolicy;
		PROCESS_MITIGATION_CHILD_PROCESS_POLICY ChildProcessPolicy;
		PROCESS_MITIGATION_SIDE_CHANNEL_ISOLATION_POLICY SideChannelIsolationPolicy;
		PROCESS_MITIGATION_USER_SHADOW_STACK_POLICY UserShadowStackPolicy;
		PROCESS_MITIGATION_REDIRECTION_TRUST_POLICY RedirectionTrustPolicy;
		PROCESS_MITIGATION_USER_POINTER_AUTH_POLICY UserPointerAuthPolicy;
		PROCESS_MITIGATION_SEHOP_POLICY SEHOPPolicy;
	};
} PROCESS_MITIGATION_POLICY_INFORMATION, *PPROCESS_MITIGATION_POLICY_INFORMATION;

typedef struct _SYSTEM_PROCESS_ID_INFORMATION
{
	HANDLE ProcessId;
	UNICODE_STRING ImageName;
} SYSTEM_PROCESS_ID_INFORMATION, *PSYSTEM_PROCESS_ID_INFORMATION;

typedef struct _KEY_BASIC_INFORMATION
{
	LARGE_INTEGER LastWriteTime;
	ULONG TitleIndex;
	ULONG NameLength;
	_Field_size_bytes_ (NameLength) WCHAR Name[1];
} KEY_BASIC_INFORMATION, *PKEY_BASIC_INFORMATION;

typedef struct _KEY_NODE_INFORMATION
{
	LARGE_INTEGER LastWriteTime;
	ULONG TitleIndex;
	ULONG ClassOffset;
	ULONG ClassLength;
	ULONG NameLength;
	_Field_size_bytes_ (NameLength) WCHAR Name[1];
	// ...
	// WCHAR Class[1];
} KEY_NODE_INFORMATION, *PKEY_NODE_INFORMATION;

typedef struct _KEY_NAME_INFORMATION
{
	ULONG NameLength;
	_Field_size_bytes_ (NameLength) WCHAR Name[1];
} KEY_NAME_INFORMATION, *PKEY_NAME_INFORMATION;

typedef struct _KEY_CACHED_INFORMATION
{
	LARGE_INTEGER LastWriteTime;
	ULONG TitleIndex;
	ULONG SubKeys;
	ULONG MaxNameLength;
	ULONG Values;
	ULONG MaxValueNameLength;
	ULONG MaxValueDataLength;
	ULONG NameLength;
	_Field_size_bytes_ (NameLength) WCHAR Name[1];
} KEY_CACHED_INFORMATION, *PKEY_CACHED_INFORMATION;

typedef struct _KEY_FULL_INFORMATION
{
	LARGE_INTEGER LastWriteTime;
	ULONG TitleIndex;
	ULONG ClassOffset;
	ULONG ClassLength;
	ULONG SubKeys;
	ULONG MaxNameLength;
	ULONG MaxClassLength;
	ULONG Values;
	ULONG MaxValueNameLength;
	ULONG MaxValueDataLength;
	WCHAR Class[1];
} KEY_FULL_INFORMATION, *PKEY_FULL_INFORMATION;

typedef struct _KEY_VALUE_BASIC_INFORMATION
{
	ULONG TitleIndex;
	ULONG Type;
	ULONG NameLength;
	_Field_size_bytes_ (NameLength) WCHAR Name[1];
} KEY_VALUE_BASIC_INFORMATION, *PKEY_VALUE_BASIC_INFORMATION;

typedef struct _KEY_VALUE_PARTIAL_INFORMATION
{
	ULONG TitleIndex;
	ULONG Type;
	ULONG DataLength;
	_Field_size_bytes_ (DataLength) UCHAR Data[1];
} KEY_VALUE_PARTIAL_INFORMATION, *PKEY_VALUE_PARTIAL_INFORMATION;

typedef struct _KEY_VALUE_FULL_INFORMATION
{
	ULONG TitleIndex;
	ULONG Type;
	ULONG DataOffset;
	ULONG DataLength;
	ULONG NameLength;
	_Field_size_bytes_ (NameLength) WCHAR Name[1];
	// ...
	// UCHAR Data[1];
} KEY_VALUE_FULL_INFORMATION, *PKEY_VALUE_FULL_INFORMATION;

typedef struct _TIME_FIELDS
{
	short Year; // 1601...
	short Month; // 1..12
	short Day; // 1..31
	short Hour; // 0..23
	short Minute; // 0..59
	short Second; // 0..59
	short Milliseconds; // 0..999
	short Weekday; // 0..6 = Sunday..Saturday
} TIME_FIELDS, *PTIME_FIELDS;

typedef struct _RTL_TIME_ZONE_INFORMATION
{
	LONG Bias;
	WCHAR StandardName[32];
	TIME_FIELDS StandardStart;
	LONG StandardBias;
	WCHAR DaylightName[32];
	TIME_FIELDS DaylightStart;
	LONG DaylightBias;
} RTL_TIME_ZONE_INFORMATION, *PRTL_TIME_ZONE_INFORMATION;

// WNF (win8+)
typedef struct _WNF_STATE_NAME
{
	ULONG Data[2];
} WNF_STATE_NAME, *PWNF_STATE_NAME;

typedef const WNF_STATE_NAME *PCWNF_STATE_NAME;

typedef enum _WNF_STATE_NAME_LIFETIME
{
	WnfWellKnownStateName,
	WnfPermanentStateName,
	WnfPersistentStateName,
	WnfTemporaryStateName
} WNF_STATE_NAME_LIFETIME;

typedef enum _WNF_STATE_NAME_INFORMATION
{
	WnfInfoStateNameExist,
	WnfInfoSubscribersPresent,
	WnfInfoIsQuiescent
} WNF_STATE_NAME_INFORMATION;

typedef enum _WNF_DATA_SCOPE
{
	WnfDataScopeSystem,
	WnfDataScopeSession,
	WnfDataScopeUser,
	WnfDataScopeProcess,
	WnfDataScopeMachine, // REDSTONE3
	WnfDataScopePhysicalMachine, // WIN11
} WNF_DATA_SCOPE;

typedef struct _WNF_TYPE_ID
{
	GUID TypeId;
} WNF_TYPE_ID, *PWNF_TYPE_ID;

typedef const WNF_TYPE_ID *PCWNF_TYPE_ID;

// rev
typedef ULONG WNF_CHANGE_STAMP, *PWNF_CHANGE_STAMP;

typedef struct _WNF_DELIVERY_DESCRIPTOR
{
	ULONG64 SubscriptionId;
	WNF_STATE_NAME StateName;
	WNF_CHANGE_STAMP ChangeStamp;
	ULONG StateDataSize;
	ULONG EventMask;
	WNF_TYPE_ID TypeId;
	ULONG StateDataOffset;
} WNF_DELIVERY_DESCRIPTOR, *PWNF_DELIVERY_DESCRIPTOR;

typedef struct _SYSTEM_PROCESSOR_INFORMATION
{
	USHORT ProcessorArchitecture;
	USHORT ProcessorLevel;
	USHORT ProcessorRevision;
	USHORT MaximumProcessors;
	ULONG ProcessorFeatureBits;
} SYSTEM_PROCESSOR_INFORMATION, *PSYSTEM_PROCESSOR_INFORMATION;

typedef enum _FOCUS_ASSIST_INFO
{
	FOCUS_ASSIST_NOT_SUPPORTED = -2,
	FOCUS_ASSIST_FAILED = -1,
	FOCUS_ASSIST_OFF = 0,
	FOCUS_ASSIST_PRIORITY_ONLY = 1,
	FOCUS_ASSIST_ALARMS_ONLY = 2
} FOCUS_ASSIST_INFO, *PFOCUS_ASSIST_INFO;

//
// Synchronization enumerations
//

typedef enum _EVENT_TYPE
{
	NotificationEvent,
	SynchronizationEvent
} EVENT_TYPE;

typedef enum _TIMER_TYPE
{
	NotificationTimer,
	SynchronizationTimer
} TIMER_TYPE;

typedef enum _WAIT_TYPE
{
	WaitAll,
	WaitAny,
	WaitNotification
} WAIT_TYPE;

typedef enum _IO_PRIORITY_HINT
{
	IoPriorityVeryLow = 0, // Defragging, content indexing and other background I/Os.
	IoPriorityLow, // Prefetching for applications.
	IoPriorityNormal, // Normal I/Os.
	IoPriorityHigh, // Used by filesystems for checkpoint I/O.
	IoPriorityCritical, // Used by memory manager. Not available for applications.
	MaxIoPriorityTypes
} IO_PRIORITY_HINT;

//
// Object attributes
//

#define OBJ_PROTECT_CLOSE 0x00000001
#define OBJ_INHERIT 0x00000002
#define OBJ_AUDIT_OBJECT_CLOSE 0x00000004
#define OBJ_NO_RIGHTS_UPGRADE 0x00000008
#define OBJ_PERMANENT 0x00000010
#define OBJ_EXCLUSIVE 0x00000020
#define OBJ_CASE_INSENSITIVE 0x00000040
#define OBJ_OPENIF 0x00000080
#define OBJ_OPENLINK 0x00000100
#define OBJ_KERNEL_HANDLE 0x00000200
#define OBJ_FORCE_ACCESS_CHECK 0x00000400
#define OBJ_IGNORE_IMPERSONATED_DEVICEMAP 0x00000800
#define OBJ_DONT_REPARSE 0x00001000
#define OBJ_VALID_ATTRIBUTES 0x00001FF2

#define OBJECT_TYPE_CREATE 0x0001
#define OBJECT_TYPE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)

#define DIRECTORY_QUERY 0x0001
#define DIRECTORY_TRAVERSE 0x0002
#define DIRECTORY_CREATE_OBJECT 0x0004
#define DIRECTORY_CREATE_SUBDIRECTORY 0x0008
#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)

#define SYMBOLIC_LINK_QUERY 0x0001
#define SYMBOLIC_LINK_SET 0x0002
#define SYMBOLIC_LINK_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)
#define SYMBOLIC_LINK_ALL_ACCESS_EX (STANDARD_RIGHTS_REQUIRED | 0xFFFF)

typedef struct _OBJECT_ATTRIBUTES
{
	ULONG Length;
	HANDLE RootDirectory;
	PUNICODE_STRING ObjectName;
	ULONG Attributes;
	PSECURITY_DESCRIPTOR SecurityDescriptor;
	PSECURITY_QUALITY_OF_SERVICE SecurityQualityOfService;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

typedef const OBJECT_ATTRIBUTES *PCOBJECT_ATTRIBUTES;

typedef struct _PROCESS_DEVICEMAP_INFORMATION
{
	union
	{
		struct
		{
			HANDLE DirectoryHandle;
		} Set;

		struct
		{
			ULONG DriveMap;
			UCHAR DriveType[32];
		} Query;
	};
} PROCESS_DEVICEMAP_INFORMATION, *PPROCESS_DEVICEMAP_INFORMATION;

#define PROCESS_LUID_DOSDEVICES_ONLY 0x00000001

typedef struct _PROCESS_DEVICEMAP_INFORMATION_EX
{
	union
	{
		struct
		{
			HANDLE DirectoryHandle;
		} Set;

		struct
		{
			ULONG DriveMap;
			UCHAR DriveType[32];
		} Query;
	};

	ULONG Flags; // PROCESS_LUID_DOSDEVICES_ONLY
} PROCESS_DEVICEMAP_INFORMATION_EX, *PPROCESS_DEVICEMAP_INFORMATION_EX;

#define NtCurrentProcess() ((HANDLE)(LONG_PTR)-1)
#define NtCurrentThread() ((HANDLE)(LONG_PTR)-2)
#define NtCurrentSession() ((HANDLE)(LONG_PTR)-3)
#define NtCurrentPeb() (NtCurrentTeb()->ProcessEnvironmentBlock)
#define RtlProcessHeap() (NtCurrentPeb()->ProcessHeap)

// Windows 8 and above
#define NtCurrentProcessToken() ((HANDLE)(LONG_PTR)-4) // NtOpenProcessToken(NtCurrentProcess())
#define NtCurrentThreadToken() ((HANDLE)(LONG_PTR)-5) // NtOpenThreadToken(NtCurrentThread())
#define NtCurrentThreadEffectiveToken() ((HANDLE)(LONG_PTR)-6) // NtOpenThreadToken(NtCurrentThread()) + NtOpenProcessToken(NtCurrentProcess())

#define NtCurrentSilo() ((HANDLE)(LONG_PTR)-1)

// Not NT, but useful.
#define NtCurrentProcessId() (NtCurrentTeb()->ClientId.UniqueProcess)
#define NtCurrentThreadId() (NtCurrentTeb()->ClientId.UniqueThread)

#define NtLastError() (NtCurrentTeb()->LastErrorValue)

#define InitializeObjectAttributes(p, n, a, r, s) { \
	(p)->Length = sizeof (OBJECT_ATTRIBUTES); \
	(p)->RootDirectory = r; \
	(p)->Attributes = a; \
	(p)->ObjectName = n; \
	(p)->SecurityDescriptor = s; \
	(p)->SecurityQualityOfService = NULL; \
	}

//
// Kernel-user shared data
//

#define PROCESSOR_FEATURE_MAX 64

typedef enum _NT_PRODUCT_TYPE
{
	NtProductWinNt = 1,
	NtProductLanManNt,
	NtProductServer
} NT_PRODUCT_TYPE, *PNT_PRODUCT_TYPE;

typedef enum _ALTERNATIVE_ARCHITECTURE_TYPE
{
	StandardDesign,
	NEC98x86,
	EndAlternatives
} ALTERNATIVE_ARCHITECTURE_TYPE;

#include <pshpack4.h>
typedef struct _KSYSTEM_TIME
{
	ULONG LowPart;
	LONG High1Time;
	LONG High2Time;
} KSYSTEM_TIME, *PKSYSTEM_TIME;
#include <poppack.h>

#include <pshpack4.h>
typedef struct _KUSER_SHARED_DATA
{
	// Current low 32-bit of tick count and tick count multiplier.
	//
	// N.B. The tick count is updated each time the clock ticks.
	ULONG TickCountLowDeprecated;
	ULONG TickCountMultiplier;

	// Current 64-bit interrupt time in 100ns units.
	volatile KSYSTEM_TIME InterruptTime;

	// Current 64-bit interrupt time in 100ns units.
	volatile KSYSTEM_TIME SystemTime;

	// Current 64-bit time zone bias.
	volatile KSYSTEM_TIME TimeZoneBias;

	// Support image magic number range for the host system.
	//
	// N.B. This is an inclusive range.
	USHORT ImageNumberLow;
	USHORT ImageNumberHigh;

	// Copy of system root in unicode.
	//
	// N.B. This field must be accessed via the RtlGetNtSystemRoot API for an accurate result.
	WCHAR NtSystemRoot[260];

	// Maximum stack trace depth if tracing enabled.
	ULONG MaxStackTraceDepth;

	// Crypto exponent value.
	ULONG CryptoExponent;

	// Time zone ID.
	ULONG TimeZoneId;
	ULONG LargePageMinimum;

	// This value controls the AIT Sampling rate.
	ULONG AitSamplingValue;

	// This value controls switchback processing.
	ULONG AppCompatFlag;

	// Current Kernel Root RNG state seed version
	ULONG64 RNGSeedVersion;

	// This value controls assertion failure handling.
	ULONG GlobalValidationRunlevel;

	volatile LONG TimeZoneBiasStamp;

	// The shared collective build number undecorated with C or F.
	// GetVersionEx hides the real number
	ULONG NtBuildNumber;

	// Product type.
	//
	// N.B. This field must be accessed via the RtlGetNtProductType API for an accurate result.
	NT_PRODUCT_TYPE NtProductType;
	BOOLEAN ProductTypeIsValid;
	BOOLEAN Reserved0[1];
	USHORT NativeProcessorArchitecture;

	// N. B. Note that each process sees a version from its PEB, but if the
	// process is running with an altered view of the system version,
	// the following two fields are used to correctly identify the
	// version.
	ULONG NtMajorVersion;
	ULONG NtMinorVersion;

	// Processor features.
	BOOLEAN ProcessorFeatures[PROCESSOR_FEATURE_MAX];

	// Reserved fields - do not use.
	ULONG Reserved1;
	ULONG Reserved3;

	// Time slippage while in debugger.
	volatile ULONG TimeSlip;

	// Alternative system architecture, e.g., NEC PC98xx on x86.
	ALTERNATIVE_ARCHITECTURE_TYPE AlternativeArchitecture;

	// Boot sequence, incremented for each boot attempt by the OS loader.
	ULONG BootId;

	// If the system is an evaluation unit, the following field contains the
	// date and time that the evaluation unit expires. A value of 0 indicates
	// that there is no expiration. A non-zero value is the UTC absolute time
	// that the system expires.
	LARGE_INTEGER SystemExpirationDate;

	// Suite support.
	//
	// N.B. This field must be accessed via the RtlGetSuiteMask API for an accurate result.
	ULONG SuiteMask;

	// TRUE if a kernel debugger is connected/enabled.
	BOOLEAN KdDebuggerEnabled;

	// Mitigation policies.
	union
	{
		UCHAR MitigationPolicies;

		struct
		{
			UCHAR NXSupportPolicy : 2;
			UCHAR SEHValidationPolicy : 2;
			UCHAR CurDirDevicesSkippedForDlls : 2;
			UCHAR Reserved : 2;
		};
	};

	// Measured duration of a single processor yield, in cycles. This is used by
	// lock packages to determine how many times to spin waiting for a state
	// change before blocking.
	USHORT CyclesPerYield;

	// Current console session Id. Always zero on non-TS systems.
	//
	// N.B. This field must be accessed via the RtlGetActiveConsoleId API for an accurate result.
	volatile ULONG ActiveConsoleId;

	// Force-dismounts cause handles to become invalid. Rather than always
	// probe handles, a serial number of dismounts is maintained that clients
	// can use to see if they need to probe handles.
	volatile ULONG DismountCount;

	// This field indicates the status of the 64-bit COM+ package on the
	// system. It indicates whether the Itermediate Language (IL) COM+
	// images need to use the 64-bit COM+ runtime or the 32-bit COM+ runtime.
	ULONG ComPlusPackage;

	// Time in tick count for system-wide last user input across all terminal
	// sessions. For MP performance, it is not updated all the time (e.g. once
	// a minute per session). It is used for idle detection.
	ULONG LastSystemRITEventTickCount;

	// Number of physical pages in the system. This can dynamically change as
	// physical memory can be added or removed from a running system.
	ULONG NumberOfPhysicalPages;

	// True if the system was booted in safe boot mode.
	BOOLEAN SafeBootMode;

	// Virtualization flags.
	UCHAR VirtualizationFlags;

	// Reserved (available for reuse).
	UCHAR Reserved12[2];

	// This is a packed bitfield that contains various flags concerning
	// the system state. They must be manipulated using interlocked
	// operations.
	//
	// N.B. DbgMultiSessionSku must be accessed via the RtlIsMultiSessionSku API for an accurate result
	union
	{
		ULONG SharedDataFlags;

		// The following bit fields are for the debugger only. Do not use.
		// Use the bit definitions instead.
		struct
		{
			ULONG DbgErrorPortPresent : 1;
			ULONG DbgElevationEnabled : 1;
			ULONG DbgVirtEnabled : 1;
			ULONG DbgInstallerDetectEnabled : 1;
			ULONG DbgLkgEnabled : 1;
			ULONG DbgDynProcessorEnabled : 1;
			ULONG DbgConsoleBrokerEnabled : 1;
			ULONG DbgSecureBootEnabled : 1;
			ULONG DbgMultiSessionSku : 1;
			ULONG DbgMultiUsersInSessionSku : 1;
			ULONG DbgStateSeparationEnabled : 1;
			ULONG SpareBits : 21;
		};
	};

	ULONG DataFlagsPad[1];

	// Depending on the processor, the code for fast system call will differ,
	// Stub code is provided pointers below to access the appropriate code.
	//
	// N.B. The following field is only used on 32-bit systems.
	ULONG64 TestRetInstruction;
	LONG64 QpcFrequency;

	// On AMD64, this value is initialized to a nonzero value if the system
	// operates with an altered view of the system service call mechanism.
	ULONG SystemCall;

	union
	{
		ULONG AllFlags;

		struct
		{
			ULONG Win32Process : 1;
			ULONG Sgx2Enclave : 1;
			ULONG VbsBasicEnclave : 1;
			ULONG SpareBits : 29;
		};
	} UserCetAvailableEnvironments;

	// Reserved, available for reuse.
	ULONG64 SystemCallPad[2];

	// The 64-bit tick count.
	union
	{
		volatile KSYSTEM_TIME TickCount;
		volatile ULONG64 TickCountQuad;

		struct
		{
			ULONG ReservedTickCountOverlay[3];
			ULONG TickCountPad[1];
		};
	};

	// Cookie for encoding pointers system wide.
	ULONG Cookie;
	ULONG CookiePad[1];

	// Client id of the process having the focus in the current
	// active console session id.
	//
	// N.B. This field must be accessed via the RtlGetConsoleSessionForegroundProcessId API for an accurate result.
	LONG64 ConsoleSessionForegroundProcessId;

	// N.B. The following data is used to implement the precise time
	// services. It is aligned on a 64-byte cache-line boundary and
	// arranged in the order of typical accesses.
	//
	// Placeholder for the (internal) time update lock.
	ULONG64 TimeUpdateLock;

	// The performance counter value used to establish the current system time.
	ULONG64 BaselineSystemTimeQpc;

	// The performance counter value used to compute the last interrupt time.
	ULONG64 BaselineInterruptTimeQpc;

	// The scaled number of system time seconds represented by a single
	// performance count (this value may vary to achieve time synchronization).
	ULONG64 QpcSystemTimeIncrement;

	// The scaled number of interrupt time seconds represented by a single
	// performance count (this value is constant after the system is booted).
	ULONG64 QpcInterruptTimeIncrement;

	// The scaling shift count applied to the performance counter system time increment.
	UCHAR QpcSystemTimeIncrementShift;

	// The scaling shift count applied to the performance counter interrupt time increment.
	UCHAR QpcInterruptTimeIncrementShift;

	// The count of unparked processors.
	USHORT UnparkedProcessorCount;

	// A bitmask of enclave features supported on this system.
	//
	// N.B. This field must be accessed via the RtlIsEnclaveFeaturePresent API for an accurate result.
	ULONG EnclaveFeatureMask[4];

	// Current coverage round for telemetry based coverage.
	ULONG TelemetryCoverageRound;

	// The following field is used for ETW user mode global logging (UMGL).
	USHORT UserModeGlobalLogger[16];

	// Settings that can enable the use of Image File Execution Options from HKCU in addition to the original HKLM.
	ULONG ImageFileExecutionOptions;

	// Generation of the kernel structure holding system language information
	ULONG LangGenerationCount;

	// Reserved (available for reuse).
	ULONG64 Reserved4;

	// Current 64-bit interrupt time bias in 100ns units.
	volatile ULONG64 InterruptTimeBias;

	// Current 64-bit performance counter bias, in performance counter units before the shift is applied.
	volatile ULONG64 QpcBias;

	// Number of active processors and groups.
	ULONG ActiveProcessorCount;
	volatile UCHAR ActiveGroupCount;

	// Reserved (available for re-use).
	UCHAR Reserved9;

	union
	{
		USHORT QpcData;

		struct
		{
			// A boolean indicating whether performance counter queries
			// can read the counter directly (bypassing the system call).
			volatile UCHAR QpcBypassEnabled;

			// Shift applied to the raw counter value to derive the QPC count.
			UCHAR QpcShift;
		};
	};

	LARGE_INTEGER TimeZoneBiasEffectiveStart;
	LARGE_INTEGER TimeZoneBiasEffectiveEnd;

	// Extended processor state configuration
	XSTATE_CONFIGURATION XState;

	KSYSTEM_TIME FeatureConfigurationChangeStamp;
	ULONG Spare;

	ULONG64 UserPointerAuthMask;
} KUSER_SHARED_DATA, *PKUSER_SHARED_DATA;
#include <poppack.h>

C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, TickCountMultiplier) == 0x0004);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, InterruptTime) == 0x0008);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, SystemTime) == 0x0014);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, TimeZoneBias) == 0x0020);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, ImageNumberLow) == 0x002C);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, ImageNumberHigh) == 0x002E);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, NtSystemRoot) == 0x0030);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, MaxStackTraceDepth) == 0x0238);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, CryptoExponent) == 0x023C);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, TimeZoneId) == 0x0240);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, LargePageMinimum) == 0x0244);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, AitSamplingValue) == 0x0248);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, RNGSeedVersion) == 0x0250);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, NtProductType) == 0x0264);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, NtMajorVersion) == 0x026C);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, NtMinorVersion) == 0x0270);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, ProcessorFeatures) == 0x0274);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, Reserved1) == 0x02b4);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, Reserved3) == 0x02b8);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, KdDebuggerEnabled) == 0x02D4);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, ActiveConsoleId) == 0x02D8);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, NumberOfPhysicalPages) == 0X02E8);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, SafeBootMode) == 0x02EC);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, TickCount) == 0x0320);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, TickCountQuad) == 0x0320);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, Cookie) == 0x0330);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, QpcBias) == 0x03B8);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, ActiveProcessorCount) == 0x03C0);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, ActiveGroupCount) == 0x03C4);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, Reserved9) == 0x03C5);
C_ASSERT (FIELD_OFFSET (KUSER_SHARED_DATA, XState) == 0x03D8);

#define USER_SHARED_DATA ((PKUSER_SHARED_DATA const)0x7FFE0000)

//
// Teb/Peb
//

#define GDI_HANDLE_BUFFER_SIZE32 34
#define GDI_HANDLE_BUFFER_SIZE64 60

#if defined(_WIN64)
#define GDI_HANDLE_BUFFER_SIZE GDI_HANDLE_BUFFER_SIZE64
#else
#define GDI_HANDLE_BUFFER_SIZE GDI_HANDLE_BUFFER_SIZE32
#endif // _WIN64

typedef ULONG GDI_HANDLE_BUFFER[GDI_HANDLE_BUFFER_SIZE];

#define GDI_BATCH_BUFFER_SIZE 310

#define RTL_MAX_DRIVE_LETTERS 32
#define RTL_DRIVE_LETTER_VALID (USHORT)0x0001

typedef struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME
{
	struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME *Previous;
	struct _ACTIVATION_CONTEXT *ActivationContext;
	ULONG Flags;
} RTL_ACTIVATION_CONTEXT_STACK_FRAME, *PRTL_ACTIVATION_CONTEXT_STACK_FRAME;

typedef struct _ACTIVATION_CONTEXT_STACK
{
	RTL_ACTIVATION_CONTEXT_STACK_FRAME *ActiveFrame;
	LIST_ENTRY FrameListCache;
	ULONG Flags;
	ULONG NextCookieSequenceNumber;
	ULONG_PTR StackId;
} ACTIVATION_CONTEXT_STACK, *PACTIVATION_CONTEXT_STACK;

typedef struct _API_SET_NAMESPACE
{
	ULONG Version;
	ULONG Size;
	ULONG Flags;
	ULONG Count;
	ULONG EntryOffset;
	ULONG HashOffset;
	ULONG HashFactor;
} API_SET_NAMESPACE, *PAPI_SET_NAMESPACE;

typedef struct _GDI_TEB_BATCH
{
	ULONG Offset;
	ULONG_PTR HDC;
	ULONG Buffer[GDI_BATCH_BUFFER_SIZE];
} GDI_TEB_BATCH, *PGDI_TEB_BATCH;

typedef struct _TEB_ACTIVE_FRAME_CONTEXT
{
	ULONG Flags;
	PSTR FrameName;
} TEB_ACTIVE_FRAME_CONTEXT, *PTEB_ACTIVE_FRAME_CONTEXT;

typedef struct _TEB_ACTIVE_FRAME
{
	ULONG Flags;
	struct _TEB_ACTIVE_FRAME *Previous;
	PTEB_ACTIVE_FRAME_CONTEXT Context;
} TEB_ACTIVE_FRAME, *PTEB_ACTIVE_FRAME;

typedef struct _PEB_LDR_DATA
{
	ULONG Length;
	BOOLEAN Initialized;
	HANDLE SsHandle;
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
	PVOID EntryInProgress;
	BOOLEAN ShutdownInProgress;
	HANDLE ShutdownThreadId;
} PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef struct _CURDIR
{
	UNICODE_STRING DosPath;
	HANDLE Handle;
} CURDIR, *PCURDIR;

typedef struct _RTL_DRIVE_LETTER_CURDIR
{
	USHORT Flags;
	USHORT Length;
	ULONG TimeStamp;
	STRING DosPath;
} RTL_DRIVE_LETTER_CURDIR, *PRTL_DRIVE_LETTER_CURDIR;

typedef struct _RTL_USER_PROCESS_PARAMETERS
{
	ULONG MaximumLength;
	ULONG Length;

	ULONG Flags;
	ULONG DebugFlags;

	HANDLE ConsoleHandle;
	ULONG ConsoleFlags;
	HANDLE StandardInput;
	HANDLE StandardOutput;
	HANDLE StandardError;

	CURDIR CurrentDirectory;
	UNICODE_STRING DllPath;
	UNICODE_STRING ImagePathName;
	UNICODE_STRING CommandLine;
	PVOID Environment;

	ULONG StartingX;
	ULONG StartingY;
	ULONG CountX;
	ULONG CountY;
	ULONG CountCharsX;
	ULONG CountCharsY;
	ULONG FillAttribute;

	ULONG WindowFlags;
	ULONG ShowWindowFlags;
	UNICODE_STRING WindowTitle;
	UNICODE_STRING DesktopInfo;
	UNICODE_STRING ShellInfo;
	UNICODE_STRING RuntimeData;
	RTL_DRIVE_LETTER_CURDIR CurrentDirectories[RTL_MAX_DRIVE_LETTERS];

	ULONG_PTR EnvironmentSize;
	ULONG_PTR EnvironmentVersion;

	PVOID PackageDependencyData;
	ULONG ProcessGroupId;
	ULONG LoaderThreads;

	UNICODE_STRING RedirectionDllName; // REDSTONE4
	UNICODE_STRING HeapPartitionName; // 19H1
	ULONG_PTR DefaultThreadpoolCpuSetMasks;
	ULONG DefaultThreadpoolCpuSetMaskCount;
	ULONG DefaultThreadpoolThreadMaximum;
	ULONG HeapMemoryTypeMask; // WIN11
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS;

typedef struct _TELEMETRY_COVERAGE_HEADER
{
	UCHAR MajorVersion;
	UCHAR MinorVersion;

	struct
	{
		USHORT TracingEnabled : 1;
		USHORT Reserved1 : 15;
	};

	ULONG HashTableEntries;
	ULONG HashIndexMask;
	ULONG TableUpdateVersion;
	ULONG TableSizeInBytes;
	ULONG LastResetTick;
	ULONG ResetRound;
	ULONG Reserved2;
	ULONG RecordedCount;
	ULONG Reserved3[4];
	ULONG HashTable[ANYSIZE_ARRAY];
} TELEMETRY_COVERAGE_HEADER, *PTELEMETRY_COVERAGE_HEADER;

typedef struct _LEAP_SECOND_DATA *PLEAP_SECOND_DATA;

typedef struct _PEB
{
	BOOLEAN InheritedAddressSpace;
	BOOLEAN ReadImageFileExecOptions;
	BOOLEAN BeingDebugged;

	union
	{
		BOOLEAN BitField;

		struct
		{
			BOOLEAN ImageUsesLargePages : 1;
			BOOLEAN IsProtectedProcess : 1;
			BOOLEAN IsImageDynamicallyRelocated : 1;
			BOOLEAN SkipPatchingUser32Forwarders : 1;
			BOOLEAN IsPackagedProcess : 1;
			BOOLEAN IsAppContainer : 1;
			BOOLEAN IsProtectedProcessLight : 1;
			BOOLEAN IsLongPathAwareProcess : 1;
		};
	};

	HANDLE Mutant;

	PVOID ImageBaseAddress;
	PPEB_LDR_DATA Ldr;
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
	PVOID SubSystemData;
	PVOID ProcessHeap;
	PRTL_CRITICAL_SECTION FastPebLock;
	PSLIST_HEADER AtlThunkSListPtr;
	PVOID IFEOKey;

	union
	{
		ULONG CrossProcessFlags;

		struct
		{
			ULONG ProcessInJob : 1;
			ULONG ProcessInitializing : 1;
			ULONG ProcessUsingVEH : 1;
			ULONG ProcessUsingVCH : 1;
			ULONG ProcessUsingFTH : 1;
			ULONG ProcessPreviouslyThrottled : 1;
			ULONG ProcessCurrentlyThrottled : 1;
			ULONG ProcessImagesHotPatched : 1; // REDSTONE5
			ULONG ReservedBits0 : 24;
		};
	};

	union
	{
		PVOID KernelCallbackTable;
		PVOID UserSharedInfoPtr;
	};

	ULONG SystemReserved;
	ULONG AtlThunkSListPtr32;
	PAPI_SET_NAMESPACE ApiSetMap;
	ULONG TlsExpansionCounter;
	PVOID TlsBitmap;
	ULONG TlsBitmapBits[2]; // TLS_MINIMUM_AVAILABLE

	PVOID ReadOnlySharedMemoryBase;
	PVOID SharedData; // HotpatchInformation
	PVOID *ReadOnlyStaticServerData;

	PVOID AnsiCodePageData; // PCPTABLEINFO
	PVOID OemCodePageData; // PCPTABLEINFO
	PVOID UnicodeCaseTableData; // PNLSTABLEINFO

	ULONG NumberOfProcessors;
	ULONG NtGlobalFlag;

	ULARGE_INTEGER CriticalSectionTimeout;
	ULONG_PTR HeapSegmentReserve;
	ULONG_PTR HeapSegmentCommit;
	ULONG_PTR HeapDeCommitTotalFreeThreshold;
	ULONG_PTR HeapDeCommitFreeBlockThreshold;

	ULONG NumberOfHeaps;
	ULONG MaximumNumberOfHeaps;
	PVOID *ProcessHeaps; // PHEAP

	PVOID GdiSharedHandleTable; // PGDI_SHARED_MEMORY
	PVOID ProcessStarterHelper;
	ULONG GdiDCAttributeList;

	PRTL_CRITICAL_SECTION LoaderLock;

	ULONG OSMajorVersion;
	ULONG OSMinorVersion;
	USHORT OSBuildNumber;
	USHORT OSCSDVersion;
	ULONG OSPlatformId;
	ULONG ImageSubsystem;
	ULONG ImageSubsystemMajorVersion;
	ULONG ImageSubsystemMinorVersion;
	KAFFINITY ActiveProcessAffinityMask;
	GDI_HANDLE_BUFFER GdiHandleBuffer;
	PVOID PostProcessInitRoutine;

	PVOID TlsExpansionBitmap;
	ULONG TlsExpansionBitmapBits[32]; // TLS_EXPANSION_SLOTS

	ULONG SessionId;

	ULARGE_INTEGER AppCompatFlags; // KACF_*
	ULARGE_INTEGER AppCompatFlagsUser;
	PVOID pShimData;
	PVOID AppCompatInfo; // APPCOMPAT_EXE_DATA

	UNICODE_STRING CSDVersion;

	PVOID ActivationContextData;
	PVOID ProcessAssemblyStorageMap;
	PVOID SystemDefaultActivationContextData;
	PVOID SystemAssemblyStorageMap;

	ULONG_PTR MinimumStackCommit;

	PVOID SparePointers[2]; // 19H1 (previously FlsCallback to FlsHighIndex)
	PVOID PatchLoaderData;
	PVOID ChpeV2ProcessInfo; // _CHPEV2_PROCESS_INFO

	ULONG AppModelFeatureState;
	ULONG SpareUlongs[2];

	USHORT ActiveCodePage;
	USHORT OemCodePage;
	USHORT UseCaseMapping;
	USHORT UnusedNlsField;

	PVOID WerRegistrationData;
	PVOID WerShipAssertPtr;

	union
	{
		PVOID pContextData; // WIN7
		PVOID pUnused; // WIN10
		PVOID EcCodeBitMap; // WIN11
	};

	PVOID pImageHeaderHash;

	union
	{
		ULONG TracingFlags;

		struct
		{
			ULONG HeapTracingEnabled : 1;
			ULONG CritSecTracingEnabled : 1;
			ULONG LibLoaderTracingEnabled : 1;
			ULONG SpareTracingBits : 29;
		};
	};

	ULONG64 CsrServerReadOnlySharedMemoryBase;
	PRTL_CRITICAL_SECTION TppWorkerpListLock;
	LIST_ENTRY TppWorkerpList;
	PVOID WaitOnAddressHashTable[128];
	PTELEMETRY_COVERAGE_HEADER TelemetryCoverageHeader; // REDSTONE3
	ULONG CloudFileFlags;
	ULONG CloudFileDiagFlags; // REDSTONE4
	CHAR PlaceholderCompatibilityMode;
	CHAR PlaceholderCompatibilityModeReserved[7];
	PLEAP_SECOND_DATA LeapSecondData; // REDSTONE5

	union
	{
		ULONG LeapSecondFlags;

		struct
		{
			ULONG SixtySecondEnabled : 1;
			ULONG Reserved : 31;
		};
	};

	ULONG NtGlobalFlag2;
	ULONG64 ExtendedFeatureDisableMask; // since WIN11
} PEB, *PPEB;

#if defined(_WIN64)
C_ASSERT(FIELD_OFFSET(PEB, SessionId) == 0x2C0);
//C_ASSERT(sizeof(PEB) == 0x7B0); // REDSTONE3
//C_ASSERT(sizeof(PEB) == 0x7B8); // REDSTONE4
//C_ASSERT(sizeof(PEB) == 0x7C8); // REDSTONE5 // 19H1
C_ASSERT(sizeof(PEB) == 0x7D0); // WIN11
#else
C_ASSERT(FIELD_OFFSET(PEB, SessionId) == 0x1D4);
//C_ASSERT(sizeof(PEB) == 0x468); // REDSTONE3
//C_ASSERT(sizeof(PEB) == 0x470); // REDSTONE4
//C_ASSERT(sizeof(PEB) == 0x480); // REDSTONE5 // 19H1
C_ASSERT(sizeof(PEB) == 0x488); // WIN11
#endif // _WIN64

typedef struct _TEB
{
	NT_TIB NtTib;

	PVOID EnvironmentPointer;
	CLIENT_ID ClientId;
	PVOID ActiveRpcHandle;
	PVOID ThreadLocalStoragePointer;
	PPEB ProcessEnvironmentBlock;

	ULONG LastErrorValue;
	ULONG CountOfOwnedCriticalSections;
	PVOID CsrClientThread;
	PVOID Win32ThreadInfo;
	ULONG User32Reserved[26];
	ULONG UserReserved[5];
	PVOID WOW32Reserved; // user-mode 32-bit (WOW64) -> 64-bit context switch function prior to kernel-mode transition
	LCID CurrentLocale;
	ULONG FpSoftwareStatusRegister;
	PVOID ReservedForDebuggerInstrumentation[16]; // Win10 PRE-RTM+

#if defined(_WIN64)
	PVOID SystemReserved1[30];
#else
	PVOID SystemReserved1[26];
#endif // _WIN64

	CHAR PlaceholderCompatibilityMode;
	BOOLEAN PlaceholderHydrationAlwaysExplicit;
	CHAR PlaceholderReserved[10];

	ULONG ProxiedProcessId;
	ACTIVATION_CONTEXT_STACK ActivationStack;

	UCHAR WorkingOnBehalfOfTicket[8];
	NTSTATUS ExceptionCode;

	PACTIVATION_CONTEXT_STACK ActivationContextStackPointer; // WS03+
	ULONG_PTR InstrumentationCallbackSp; // Win10+
	ULONG_PTR InstrumentationCallbackPreviousPc; // Win10+
	ULONG_PTR InstrumentationCallbackPreviousSp; // Win10+

#if defined(_WIN64)
	ULONG TxFsContext;
#endif // _WIN64

	BOOLEAN InstrumentationCallbackDisabled;

#if defined(_WIN64)
	BOOLEAN UnalignedLoadStoreExceptions;
#else
	UCHAR SpareBytes[23];
	ULONG TxFsContext;
#endif // _WIN64

	GDI_TEB_BATCH GdiTebBatch;
	CLIENT_ID RealClientId;
	HANDLE GdiCachedProcessHandle;
	ULONG GdiClientPID;
	ULONG GdiClientTID;
	PVOID GdiThreadLocalInfo;
	ULONG_PTR Win32ClientInfo[62];
	PVOID glDispatchTable[233];
	ULONG_PTR glReserved1[29];
	PVOID glReserved2;
	PVOID glSectionInfo;
	PVOID glSection;
	PVOID glTable;
	PVOID glCurrentRC;
	PVOID glContext;

	NTSTATUS LastStatusValue;
	UNICODE_STRING StaticUnicodeString;
	WCHAR StaticUnicodeBuffer[261];

	PVOID DeallocationStack;
	PVOID TlsSlots[TLS_MINIMUM_AVAILABLE];
	LIST_ENTRY TlsLinks;

	PVOID Vdm;
	PVOID ReservedForNtRpc;
	PVOID DbgSsReserved[2];

	ULONG HardErrorMode;

#if defined(_WIN64)
	PVOID Instrumentation[11];
#else
	PVOID Instrumentation[9];
#endif // _WIN64

	GUID ActivityId;

	PVOID SubProcessTag;
	PVOID PerflibData;
	PVOID EtwTraceData;
	PVOID WinSockData;
	ULONG GdiBatchCount;

	union
	{
		PROCESSOR_NUMBER CurrentIdealProcessor;
		ULONG IdealProcessorValue;

		struct
		{
			UCHAR ReservedPad0;
			UCHAR ReservedPad1;
			UCHAR ReservedPad2;
			UCHAR IdealProcessor;
		};
	};

	ULONG GuaranteedStackBytes; // late WS03+
	PVOID ReservedForPerf;
	PVOID ReservedForOle;
	ULONG WaitingOnLoaderLock;
	PVOID SavedPriorityState;
	ULONG_PTR ReservedForCodeCoverage;
	PVOID ThreadPoolData;
	PVOID *TlsExpansionSlots;

#if defined(_WIN64)
	PVOID DeallocationBStore;
	PVOID BStoreLimit;
#endif // _WIN64

	ULONG MuiGeneration;
	ULONG IsImpersonating;
	PVOID NlsCache;
	PVOID pShimData;
	ULONG HeapData;
	HANDLE CurrentTransactionHandle;
	PTEB_ACTIVE_FRAME ActiveFrame;
	PVOID FlsData;

	PVOID PreferredLanguages;
	PVOID UserPrefLanguages;
	PVOID MergedPrefLanguages;
	ULONG MuiImpersonation;

	union
	{
		USHORT CrossTebFlags;
		USHORT SpareCrossTebBits : 16;
	};

	union
	{
		USHORT SameTebFlags;

		struct
		{
			USHORT SafeThunkCall : 1;
			USHORT InDebugPrint : 1;
			USHORT HasFiberData : 1;
			USHORT SkipThreadAttach : 1;
			USHORT WerInShipAssertCode : 1;
			USHORT RanProcessInit : 1;
			USHORT ClonedThread : 1;
			USHORT SuppressDebugMsg : 1;
			USHORT DisableUserStackWalk : 1;
			USHORT RtlExceptionAttached : 1;
			USHORT InitialThread : 1;
			USHORT SessionAware : 1;
			USHORT LoadOwner : 1;
			USHORT LoaderWorker : 1;
			USHORT SkipLoaderInit : 1;
			USHORT SkipFileAPIBrokering : 1;
		};
	};

	PVOID TxnScopeEnterCallback;
	PVOID TxnScopeExitCallback;
	PVOID TxnScopeContext;
	ULONG LockCount;
	LONG WowTebOffset;
	PVOID ResourceRetValue;
	PVOID ReservedForWdf;
	ULONG64 ReservedForCrt;
	GUID EffectiveContainerId;
	ULONG64 LastSleepCounter; // win11
	ULONG SpinCallCount;
	ULONG64 ExtendedFeatureDisableMask;
} TEB, *PTEB;

#if defined(_WIN64)
C_ASSERT (FIELD_OFFSET (TEB, ProcessEnvironmentBlock) == 0x0060);
C_ASSERT (FIELD_OFFSET (TEB, Win32ThreadInfo) == 0x0078);
C_ASSERT (FIELD_OFFSET (TEB, SystemReserved1) == 0x0190);
C_ASSERT (FIELD_OFFSET (TEB, ReservedForDebuggerInstrumentation) == 0x0110);
C_ASSERT (FIELD_OFFSET (TEB, ExceptionCode) == 0x02C0);
C_ASSERT (FIELD_OFFSET (TEB, InstrumentationCallbackDisabled) == 0x02EC);
C_ASSERT (FIELD_OFFSET (TEB, LastStatusValue) == 0x1250);
#else
C_ASSERT (FIELD_OFFSET (TEB, ProcessEnvironmentBlock) == 0x0030);
C_ASSERT (FIELD_OFFSET (TEB, Win32ThreadInfo) == 0x0040);
C_ASSERT (FIELD_OFFSET (TEB, SystemReserved1) == 0x010C);
C_ASSERT (FIELD_OFFSET (TEB, ReservedForDebuggerInstrumentation) == 0x00CC);
C_ASSERT (FIELD_OFFSET (TEB, ExceptionCode) == 0x01A4);
C_ASSERT (FIELD_OFFSET (TEB, InstrumentationCallbackDisabled) == 0x01B8);
C_ASSERT (FIELD_OFFSET (TEB, LastStatusValue) == 0x0BF4);
#endif // _WIN64

typedef struct _PROCESS_BASIC_INFORMATION
{
	NTSTATUS ExitStatus;
	PPEB PebBaseAddress;
	KAFFINITY AffinityMask;
	KPRIORITY BasePriority;
	HANDLE UniqueProcessId;
	HANDLE InheritedFromUniqueProcessId;
} PROCESS_BASIC_INFORMATION, *PPROCESS_BASIC_INFORMATION;

//
// Heaps
//

typedef NTSTATUS (NTAPI *PRTL_HEAP_COMMIT_ROUTINE)(
	_In_ PVOID Base,
	_Inout_ PVOID *CommitAddress,
	_Inout_ PULONG_PTR CommitSize
	);

typedef struct _RTL_HEAP_PARAMETERS
{
	ULONG Length;
	ULONG_PTR SegmentReserve;
	ULONG_PTR SegmentCommit;
	ULONG_PTR DeCommitFreeBlockThreshold;
	ULONG_PTR DeCommitTotalFreeThreshold;
	ULONG_PTR MaximumAllocationSize;
	ULONG_PTR VirtualMemoryThreshold;
	ULONG_PTR InitialCommit;
	ULONG_PTR InitialReserve;
	PRTL_HEAP_COMMIT_ROUTINE CommitRoutine;
	ULONG_PTR Reserved[2];
} RTL_HEAP_PARAMETERS, *PRTL_HEAP_PARAMETERS;

typedef enum _SECTION_INFORMATION_CLASS
{
	SectionBasicInformation, // q; SECTION_BASIC_INFORMATION
	SectionImageInformation, // q; SECTION_IMAGE_INFORMATION
	SectionRelocationInformation, // q; PVOID RelocationAddress // name:wow64:whNtQuerySection_SectionRelocationInformation // since WIN7
	SectionOriginalBaseInformation, // q; ULONG_PTR RelocationDelta // name:wow64:whNtQuerySection_SectionRelocationInformation // since WIN7
	SectionInternalImageInformation, // q; PVOID BaseAddress // since REDSTONE
	MaxSectionInfoClass
} SECTION_INFORMATION_CLASS;

typedef enum _HEAP_COMPATIBILITY_MODE
{
	HEAP_COMPATIBILITY_STANDARD = 0UL,
	HEAP_COMPATIBILITY_LAL = 1UL,
	HEAP_COMPATIBILITY_LFH = 2UL,
} HEAP_COMPATIBILITY_MODE;

#define HEAP_SETTABLE_USER_VALUE 0x00000100
#define HEAP_SETTABLE_USER_FLAG1 0x00000200
#define HEAP_SETTABLE_USER_FLAG2 0x00000400
#define HEAP_SETTABLE_USER_FLAG3 0x00000800
#define HEAP_SETTABLE_USER_FLAGS 0x00000e00

#define HEAP_CLASS_0 0x00000000 // Process heap
#define HEAP_CLASS_1 0x00001000 // Private heap
#define HEAP_CLASS_2 0x00002000 // Kernel heap
#define HEAP_CLASS_3 0x00003000 // GDI heap
#define HEAP_CLASS_4 0x00004000 // User heap
#define HEAP_CLASS_5 0x00005000 // Console heap
#define HEAP_CLASS_6 0x00006000 // User desktop heap
#define HEAP_CLASS_7 0x00007000 // CSR shared heap
#define HEAP_CLASS_8 0x00008000 // CSR port heap
#define HEAP_CLASS_MASK 0x0000f000

typedef NTSTATUS (NTAPI *PUSER_THREAD_START_ROUTINE)(
	_In_ PVOID ThreadParameter
	);

typedef struct _SECTION_IMAGE_INFORMATION
{
	PVOID TransferAddress;
	ULONG ZeroBits;
	ULONG_PTR MaximumStackSize;
	ULONG_PTR CommittedStackSize;
	ULONG SubSystemType;

	union
	{
		struct
		{
			USHORT SubSystemMinorVersion;
			USHORT SubSystemMajorVersion;
		};

		ULONG SubSystemVersion;
	};

	union
	{
		struct
		{
			USHORT MajorOperatingSystemVersion;
			USHORT MinorOperatingSystemVersion;
		};

		ULONG OperatingSystemVersion;
	};

	USHORT ImageCharacteristics;
	USHORT DllCharacteristics;
	USHORT Machine;
	BOOLEAN ImageContainsCode;

	union
	{
		UCHAR ImageFlags;

		struct
		{
			UCHAR ComPlusNativeReady : 1;
			UCHAR ComPlusILOnly : 1;
			UCHAR ImageDynamicallyRelocated : 1;
			UCHAR ImageMappedFlat : 1;
			UCHAR BaseBelow4gb : 1;
			UCHAR ComPlusPrefer32bit : 1;
			UCHAR Reserved : 2;
		};
	};

	ULONG LoaderFlags;
	ULONG ImageFileSize;
	ULONG CheckSum;
} SECTION_IMAGE_INFORMATION, *PSECTION_IMAGE_INFORMATION;

typedef struct _RTL_USER_PROCESS_INFORMATION
{
	ULONG Length;
	HANDLE ProcessHandle;
	HANDLE ThreadHandle;
	CLIENT_ID ClientId;
	SECTION_IMAGE_INFORMATION ImageInformation;
} RTL_USER_PROCESS_INFORMATION, *PRTL_USER_PROCESS_INFORMATION;

typedef struct _OBJECT_DIRECTORY_INFORMATION
{
	UNICODE_STRING Name;
	UNICODE_STRING TypeName;
} OBJECT_DIRECTORY_INFORMATION, *POBJECT_DIRECTORY_INFORMATION;

#define DIRECTORY_QUERY 0x0001
#define DIRECTORY_TRAVERSE 0x0002
#define DIRECTORY_CREATE_OBJECT 0x0004
#define DIRECTORY_CREATE_SUBDIRECTORY 0x0008
#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)

typedef struct _RTLP_CURDIR_REF
{
	LONG ReferenceCount;
	HANDLE DirectoryHandle;
} RTLP_CURDIR_REF, *PRTLP_CURDIR_REF;

typedef struct _RTL_RELATIVE_NAME_U
{
	UNICODE_STRING RelativeName;
	HANDLE ContainingDirectory;
	PRTLP_CURDIR_REF CurDirRef;
} RTL_RELATIVE_NAME_U, *PRTL_RELATIVE_NAME_U;

typedef enum _RTL_PATH_TYPE
{
	RtlPathTypeUnknown,
	RtlPathTypeUncAbsolute,
	RtlPathTypeDriveAbsolute,
	RtlPathTypeDriveRelative,
	RtlPathTypeRooted,
	RtlPathTypeRelative,
	RtlPathTypeLocalDevice,
	RtlPathTypeRootLocalDevice
} RTL_PATH_TYPE;

typedef struct _STRING
{
	USHORT Length;
	USHORT MaximumLength;
	_Field_size_bytes_part_opt_ (MaximumLength, Length) PCHAR Buffer;
} ANSI_STRING, *PANSI_STRING;

typedef struct _IO_STATUS_BLOCK
{
	union
	{
		NTSTATUS Status;
		PVOID Pointer;
	};

	ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;

typedef struct _FILE_RENAME_INFORMATION
{
	BOOLEAN ReplaceIfExists;
	HANDLE RootDirectory;
	ULONG FileNameLength;
	_Field_size_bytes_ (FileNameLength) WCHAR FileName[1];
} FILE_RENAME_INFORMATION, *PFILE_RENAME_INFORMATION;

typedef struct _LDR_RESOURCE_INFO
{
	ULONG_PTR Type;
	ULONG_PTR Name;
	ULONG_PTR Language;
} LDR_RESOURCE_INFO, *PLDR_RESOURCE_INFO;

typedef enum _PS_CREATE_STATE
{
	PsCreateInitialState,
	PsCreateFailOnFileOpen,
	PsCreateFailOnSectionCreate,
	PsCreateFailExeFormat,
	PsCreateFailMachineMismatch,
	PsCreateFailExeName, // Debugger specified
	PsCreateSuccess,
	PsCreateMaximumStates
} PS_CREATE_STATE;

typedef enum _ProcessCreateInitFlag
{
	None,
	WriteOutputOnExit,
	DetectManifest,
	IFEOSkipDebugger,
	IFEODoNotPropagateKeyState,
} ProcessCreateInitFlag;

typedef struct _PS_CREATE_INFO
{
	ULONG_PTR Size;
	PS_CREATE_STATE State;

	union
	{
		// PsCreateInitialState
		struct
		{
			union
			{
				ULONG InitFlags;

				struct
				{
					UCHAR WriteOutputOnExit : 1;
					UCHAR DetectManifest : 1;
					UCHAR IFEOSkipDebugger : 1;
					UCHAR IFEODoNotPropagateKeyState : 1;
					UCHAR SpareBits1 : 4;
					UCHAR SpareBits2 : 8;
					USHORT ProhibitedImageCharacteristics : 16;
				};
			};
			ACCESS_MASK AdditionalFileAccess;
		} InitState;

		// PsCreateFailOnSectionCreate
		struct
		{
			HANDLE FileHandle;
		} FailSection;

		// PsCreateFailExeFormat
		struct
		{
			USHORT DllCharacteristics;
		} ExeFormat;

		// PsCreateFailExeName
		struct
		{
			HANDLE IFEOKey;
		} ExeName;

		// PsCreateSuccess
		struct
		{
			union
			{
				ULONG OutputFlags;

				struct
				{
					UCHAR ProtectedProcess : 1;
					UCHAR AddressSpaceOverride : 1;
					UCHAR DevOverrideEnabled : 1; // from Image File Execution Options
					UCHAR ManifestDetected : 1;
					UCHAR ProtectedProcessLight : 1;
					UCHAR SpareBits1 : 3;
					UCHAR SpareBits2 : 8;
					USHORT SpareBits3 : 16;
				};
			};

			HANDLE FileHandle;
			HANDLE SectionHandle;
			ULONG64 UserProcessParametersNative;
			ULONG UserProcessParametersWow64;
			ULONG CurrentParameterFlags;
			ULONG64 PebAddressNative;
			ULONG PebAddressWow64;
			ULONG64 ManifestAddress;
			ULONG ManifestSize;
		} SuccessState;
	};
} PS_CREATE_INFO, *PPS_CREATE_INFO;

typedef struct _PS_ATTRIBUTE
{
	ULONG_PTR Attribute;
	ULONG_PTR Size;

	union
	{
		ULONG_PTR Value;
		PVOID ValuePtr;
	};

	PULONG_PTR ReturnLength;
} PS_ATTRIBUTE, *PPS_ATTRIBUTE;

typedef struct _PS_ATTRIBUTE_LIST
{
	ULONG_PTR TotalLength;
	PS_ATTRIBUTE Attributes[5];
} PS_ATTRIBUTE_LIST, *PPS_ATTRIBUTE_LIST;

typedef enum _PS_ATTRIBUTE_NUM
{
	PsAttributeParentProcess, // in HANDLE
	PsAttributeDebugObject, // in HANDLE
	PsAttributeToken, // in HANDLE
	PsAttributeClientId, // out PCLIENT_ID
	PsAttributeTebAddress, // out PTEB *
	PsAttributeImageName, // in PWSTR
	PsAttributeImageInfo, // out PSECTION_IMAGE_INFORMATION
	PsAttributeMemoryReserve, // in PPS_MEMORY_RESERVE
	PsAttributePriorityClass, // in UCHAR
	PsAttributeErrorMode, // in ULONG
	PsAttributeStdHandleInfo, // 10, in PPS_STD_HANDLE_INFO
	PsAttributeHandleList, // in HANDLE[]
	PsAttributeGroupAffinity, // in PGROUP_AFFINITY
	PsAttributePreferredNode, // in PUSHORT
	PsAttributeIdealProcessor, // in PPROCESSOR_NUMBER
	PsAttributeUmsThread, // ? in PUMS_CREATE_THREAD_ATTRIBUTES
	PsAttributeMitigationOptions, // in PPS_MITIGATION_OPTIONS_MAP (PROCESS_CREATION_MITIGATION_POLICY_*) // since WIN8
	PsAttributeProtectionLevel, // in PS_PROTECTION // since WINBLUE
	PsAttributeSecureProcess, // in PPS_TRUSTLET_CREATE_ATTRIBUTES, since THRESHOLD
	PsAttributeJobList, // in HANDLE[]
	PsAttributeChildProcessPolicy, // 20, in PULONG (PROCESS_CREATION_CHILD_PROCESS_*) // since THRESHOLD2
	PsAttributeAllApplicationPackagesPolicy, // in PULONG (PROCESS_CREATION_ALL_APPLICATION_PACKAGES_*) // since REDSTONE
	PsAttributeWin32kFilter, // in PWIN32K_SYSCALL_FILTER
	PsAttributeSafeOpenPromptOriginClaim, // in SE_SAFE_OPEN_PROMPT_RESULTS
	PsAttributeBnoIsolation, // in PPS_BNO_ISOLATION_PARAMETERS // since REDSTONE2
	PsAttributeDesktopAppPolicy, // in PULONG (PROCESS_CREATION_DESKTOP_APP_*)
	PsAttributeChpe, // in BOOLEAN // since REDSTONE3
	PsAttributeMitigationAuditOptions, // in PPS_MITIGATION_AUDIT_OPTIONS_MAP (PROCESS_CREATION_MITIGATION_AUDIT_POLICY_*) // since 21H1
	PsAttributeMachineType, // in USHORT // since 21H2
	PsAttributeComponentFilter,
	PsAttributeEnableOptionalXStateFeatures, // since WIN11
	PsAttributeMax
} PS_ATTRIBUTE_NUM;

#define PS_ATTRIBUTE_NUMBER_MASK 0x0000FFFF
#define PS_ATTRIBUTE_THREAD 0x00010000 // may be used with thread creation
#define PS_ATTRIBUTE_INPUT 0x00020000 // input only
#define PS_ATTRIBUTE_ADDITIVE 0x00040000 // "accumulated" e.g. bitmasks, counters, etc.

#define PsAttributeValue(Number, Thread, Input, Additive) \
	(((Number) & PS_ATTRIBUTE_NUMBER_MASK) | \
	((Thread) ? PS_ATTRIBUTE_THREAD : 0) | \
	((Input) ? PS_ATTRIBUTE_INPUT : 0) | \
	((Additive) ? PS_ATTRIBUTE_ADDITIVE : 0))

#define PS_ATTRIBUTE_PARENT_PROCESS \
	PsAttributeValue(PsAttributeParentProcess, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_DEBUG_OBJECT \
	PsAttributeValue(PsAttributeDebugObject, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_TOKEN \
	PsAttributeValue(PsAttributeToken, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_CLIENT_ID \
	PsAttributeValue(PsAttributeClientId, TRUE, FALSE, FALSE)
#define PS_ATTRIBUTE_TEB_ADDRESS \
	PsAttributeValue(PsAttributeTebAddress, TRUE, FALSE, FALSE)
#define PS_ATTRIBUTE_IMAGE_NAME \
	PsAttributeValue(PsAttributeImageName, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_IMAGE_INFO \
	PsAttributeValue(PsAttributeImageInfo, FALSE, FALSE, FALSE)
#define PS_ATTRIBUTE_MEMORY_RESERVE \
	PsAttributeValue(PsAttributeMemoryReserve, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_PRIORITY_CLASS \
	PsAttributeValue(PsAttributePriorityClass, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_ERROR_MODE \
	PsAttributeValue(PsAttributeErrorMode, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_STD_HANDLE_INFO \
	PsAttributeValue(PsAttributeStdHandleInfo, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_HANDLE_LIST \
	PsAttributeValue(PsAttributeHandleList, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_GROUP_AFFINITY \
	PsAttributeValue(PsAttributeGroupAffinity, TRUE, TRUE, FALSE)
#define PS_ATTRIBUTE_PREFERRED_NODE \
	PsAttributeValue(PsAttributePreferredNode, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_IDEAL_PROCESSOR \
	PsAttributeValue(PsAttributeIdealProcessor, TRUE, TRUE, FALSE)
#define PS_ATTRIBUTE_UMS_THREAD \
	PsAttributeValue(PsAttributeUmsThread, TRUE, TRUE, FALSE)
#define PS_ATTRIBUTE_MITIGATION_OPTIONS \
	PsAttributeValue(PsAttributeMitigationOptions, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_PROTECTION_LEVEL \
	PsAttributeValue(PsAttributeProtectionLevel, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_SECURE_PROCESS \
	PsAttributeValue(PsAttributeSecureProcess, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_JOB_LIST \
	PsAttributeValue(PsAttributeJobList, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_CHILD_PROCESS_POLICY \
	PsAttributeValue(PsAttributeChildProcessPolicy, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_ALL_APPLICATION_PACKAGES_POLICY \
	PsAttributeValue(PsAttributeAllApplicationPackagesPolicy, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_WIN32K_FILTER \
	PsAttributeValue(PsAttributeWin32kFilter, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_SAFE_OPEN_PROMPT_ORIGIN_CLAIM \
	PsAttributeValue(PsAttributeSafeOpenPromptOriginClaim, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_BNO_ISOLATION \
	PsAttributeValue(PsAttributeBnoIsolation, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_DESKTOP_APP_POLICY \
	PsAttributeValue(PsAttributeDesktopAppPolicy, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_CHPE \
	PsAttributeValue(PsAttributeChpe, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_MITIGATION_AUDIT_OPTIONS \
	PsAttributeValue(PsAttributeMitigationAuditOptions, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_MACHINE_TYPE \
	PsAttributeValue(PsAttributeMachineType, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_COMPONENT_FILTER \
	PsAttributeValue(PsAttributeComponentFilter, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_ENABLE_OPTIONAL_XSTATE_FEATURES \
	PsAttributeValue(PsAttributeEnableOptionalXStateFeatures, TRUE, TRUE, FALSE)

typedef enum _SECTION_INHERIT
{
	ViewShare = 1,
	ViewUnmap = 2
} SECTION_INHERIT;

#define MEM_EXECUTE_OPTION_ENABLE 0x01
#define MEM_EXECUTE_OPTION_DISABLE 0x02
#define MEM_EXECUTE_OPTION_DISABLE_THUNK_EMULATION 0x04
#define MEM_EXECUTE_OPTION_PERMANENT 0x08
#define MEM_EXECUTE_OPTION_EXECUTE_DISPATCH_ENABLE 0x10
#define MEM_EXECUTE_OPTION_IMAGE_DISPATCH_ENABLE 0x20
#define MEM_EXECUTE_OPTION_DISABLE_EXCEPTION_CHAIN_VALIDATION 0x40
#define MEM_EXECUTE_OPTION_VALID_FLAGS 0x7F

typedef VOID (NTAPI *PIO_APC_ROUTINE)(
	_In_ PVOID ApcContext,
	_In_ PIO_STATUS_BLOCK IoStatusBlock,
	_In_ ULONG Reserved
	);

#define RESOURCE_TYPE_LEVEL 0
#define RESOURCE_NAME_LEVEL 1
#define RESOURCE_LANGUAGE_LEVEL 2
#define RESOURCE_DATA_LEVEL 3

#define LDR_GET_DLL_HANDLE_EX_UNCHANGED_REFCOUNT 0x00000001
#define LDR_GET_DLL_HANDLE_EX_PIN 0x00000002

#define LDR_GET_PROCEDURE_ADDRESS_DONT_RECORD_FORWARDER 0x00000001

#define LDR_IS_DATAFILE(DllHandle) (((ULONG_PTR)(DllHandle)) & (ULONG_PTR)1)
#define LDR_IS_IMAGEMAPPING(DllHandle) (((ULONG_PTR)(DllHandle)) & (ULONG_PTR)2)
#define LDR_IS_RESOURCE(DllHandle) (LDR_IS_IMAGEMAPPING(DllHandle) || LDR_IS_DATAFILE(DllHandle))
#define LDR_MAPPEDVIEW_TO_DATAFILE(BaseAddress) ((PVOID)(((ULONG_PTR)(BaseAddress)) | (ULONG_PTR)1))
#define LDR_MAPPEDVIEW_TO_IMAGEMAPPING(BaseAddress) ((PVOID)(((ULONG_PTR)(BaseAddress)) | (ULONG_PTR)2))
#define LDR_DATAFILE_TO_MAPPEDVIEW(DllHandle) ((PVOID)(((ULONG_PTR)(DllHandle)) & ~(ULONG_PTR)1))
#define LDR_IMAGEMAPPING_TO_MAPPEDVIEW(DllHandle) ((PVOID)(((ULONG_PTR)(DllHandle)) & ~(ULONG_PTR)2))

#define EFI_VARIABLE_NON_VOLATILE 0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS 0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS 0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD 0x00000008
#define EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS 0x00000010
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS 0x00000020
#define EFI_VARIABLE_APPEND_WRITE 0x00000040
#define EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS 0x00000080

typedef struct
{
	BYTE byte0; // +00 (+0xB8)
	BYTE byte1; // +01
	BYTE byte2; // +02
	BYTE byte3; // +02
	ULONG64 DUMMY; // +08 (+0xC0)
	ULONG_PTR ManifestAddress; // +10 (+0xC8)
	ULONG64 ManifestSize; // +18 (+0xD0)
	HANDLE SectionHandle; // +20
	ULONG64 Offset; // +28
	ULONG_PTR Size; // +30
} BASE_SXS_STREAM; // 0x38

typedef struct _CSR_CAPTURE_BUFFER
{
	ULONG Size;
	struct _CSR_CAPTURE_BUFFER* PreviousCaptureBuffer;
	ULONG PointerCount;
	PVOID BufferEnd;
	ULONG_PTR PointerOffsetsArray[ANYSIZE_ARRAY];
} CSR_CAPTURE_BUFFER, * PCSR_CAPTURE_BUFFER;

typedef enum _BASESRV_API_NUMBER
{
	BasepCreateProcess,
	BasepCreateThread,
	BasepGetTempFile,
	BasepExitProcess,
	BasepDebugProcess,
	BasepCheckVDM,
	BasepUpdateVDMEntry,
	BasepGetNextVDMCommand,
	BasepExitVDM,
	BasepIsFirstVDM,
	BasepGetVDMExitCode,
	BasepSetReenterCount,
	BasepSetProcessShutdownParam,
	BasepGetProcessShutdownParam,
	BasepNlsSetUserInfo,
	BasepNlsSetMultipleUserInfo,
	BasepNlsCreateSection,
	BasepSetVDMCurDirs,
	BasepGetVDMCurDirs,
	BasepBatNotification,
	BasepRegisterWowExec,
	BasepSoundSentryNotification,
	BasepRefreshIniFileMapping,
	BasepDefineDosDevice,
	BasepSetTermsrvAppInstallMode,
	BasepNlsUpdateCacheCount,
	BasepSetTermsrvClientTimeZone,
	BasepSxsCreateActivationContext,
	BasepDebugProcessStop,
	BasepRegisterThread,
	BasepNlsGetUserInfo,
} BASESRV_API_NUMBER, * PBASESRV_API_NUMBER;

#define CSR_MAKE_API_NUMBER( DllIndex, ApiIndex ) \
	(ULONG)(((DllIndex) << 16) | (ApiIndex))

#define CSRSRV_SERVERDLL_INDEX 0
#define CSRSRV_FIRST_API_NUMBER 0

#define BASESRV_SERVERDLL_INDEX 1
#define BASESRV_FIRST_API_NUMBER 0

#define CONSRV_SERVERDLL_INDEX 2
#define CONSRV_FIRST_API_NUMBER 512

#define USERSRV_SERVERDLL_INDEX 3
#define USERSRV_FIRST_API_NUMBER 1024

typedef struct _BASE_SXS_CREATEPROCESS_MSG
{
	ULONG Flags; // +00 // direct set, value = 0x40
	ULONG ProcessParameterFlags; // +04 // direct set, value = 0x4001
	HANDLE FileHandle; // +08 // we can get this value
	UNICODE_STRING SxsWin32ExePath; // +10 // UNICODE_STRING, we can build!
	UNICODE_STRING SxsNtExePath; // +20 // UNICODE_STRING, we can build!
	BYTE Field30[0x10]; // +30 // blank, ignore
	BASE_SXS_STREAM PolicyStream; // +40 // !!!
	UNICODE_STRING AssemblyName; // +78 // blank, ignore
	UNICODE_STRING FileName3; // +88 // UNICODE_STRING, we can build!
	BYTE Field98[0x10]; // +98 // blank, ignore
	UNICODE_STRING FileName4; // +a8 // UNICODE_STRING, we can build!
	BYTE OtherFileds[0x110]; // +b8 // blank, ignore
} BASE_SXS_CREATEPROCESS_MSG, *PBASE_SXS_CREATEPROCESS_MSG;

typedef struct _BASE_CREATEPROCESS_MSG
{
	HANDLE ProcessHandle; // +00 // can get
	HANDLE ThreadHandle; // +08 // can get
	CLIENT_ID ClientId; // +10 // can get, PID, TID
	ULONG CreationFlags; // +20 // direct set, must be zero
	ULONG VdmBinaryType; // +24 // direct set, must be zero
	ULONG VdmTask; // +28 // ignore
	//ULONG_PTR VdmTask; // modified value
	HANDLE hVDM; // +30 // ignore
	BASE_SXS_CREATEPROCESS_MSG Sxs; // +38 // deep, need analyze, (for BASE_API_MSG, start with 0x78)
	ULONG64 PebAddressNative; // +200 // can get
	ULONG_PTR PebAddressWow64; // +208 // direct set, must be zero (Win64 limit)
	USHORT ProcessorArchitecture; // +210 // direct set, must be 9 (AMD64 limit)
} BASE_CREATEPROCESS_MSG, *PBASE_CREATEPROCESS_MSG;

typedef struct _PORT_MESSAGE_HEADER
{
	union
	{
		struct
		{
			SHORT DataLength;
			SHORT TotalLength;
		} s1;

		ULONG Length;
	} u1;

	union
	{
		struct
		{
			SHORT Type;
			SHORT DataInfoOffset;
		} s2;

		ULONG ZeroInit;
	} u2;

	union
	{
		CLIENT_ID ClientId;
		DOUBLE DoNotUseThisField;
	};

	ULONG MessageId;

	union
	{
		ULONG_PTR ClientViewSize;
		ULONG CallbackId;
	};
} PORT_MESSAGE_HEADER, *PPORT_MESSAGE_HEADER;

typedef struct _CSR_CAPTURE_HEADER
{
	ULONG Length;
	PVOID RelatedCaptureBuffer; // real: PCSR_CAPTURE_HEADER
	ULONG CountMessagePointers;
	PCHAR FreeSpace;
	ULONG_PTR MessagePointerOffsets[1]; // Offsets within CSR_API_MSG of pointers
} CSR_CAPTURE_HEADER, *PCSR_CAPTURE_HEADER;

typedef struct _PORT_MESSAGE
{
	PORT_MESSAGE_HEADER Header; // 0x00
	PCSR_CAPTURE_HEADER CaptureBuffer; // 0x28
	ULONG ApiNumber; // 0x30
	ULONG ReturnValue; // 0x34
	ULONG64 Reserved; // 0x38
} PORT_MESSAGE, *PPORT_MESSAGE;

typedef struct
{
	PORT_MESSAGE PortHeader;
	BASE_CREATEPROCESS_MSG CreateProcessMSG; // 0x40
} BASE_API_MSG, *PBASE_API_MSG;

#define GUID_VERSION_MAC 1
#define GUID_VERSION_DCE 2
#define GUID_VERSION_MD5 3
#define GUID_VERSION_RANDOM 4
#define GUID_VERSION_SHA1 5
#define GUID_VERSION_TIME 6
#define GUID_VERSION_EPOCH 7
#define GUID_VERSION_VENDOR 8

#define GUID_VARIANT_NCS_MASK 0x80
#define GUID_VARIANT_NCS 0x00
#define GUID_VARIANT_STANDARD_MASK 0xC0
#define GUID_VARIANT_STANDARD 0x80
#define GUID_VARIANT_MICROSOFT_MASK 0xE0
#define GUID_VARIANT_MICROSOFT 0xC0
#define GUID_VARIANT_RESERVED_MASK 0xE0
#define GUID_VARIANT_RESERVED 0xE0

typedef union _GUID_EX
{
	GUID Guid;
	UCHAR Data[16];

	struct
	{
		ULONG TimeLowPart;
		USHORT TimeMidPart;
		USHORT TimeHighPart;
		UCHAR ClockSequenceHigh;
		UCHAR ClockSequenceLow;
		UCHAR Node[6];
	} s;

	struct
	{
		ULONG Part0;
		USHORT Part32;
		UCHAR Part48;
		UCHAR Part56 : 4;
		UCHAR Version : 4;
		UCHAR Variant;
		UCHAR Part72;
		USHORT Part80;
		ULONG Part96;
	} s2;
} GUID_EX, *PGUID_EX;

//
// nt functions
//

EXTERN_C_START

NTSYSCALLAPI
NTSTATUS
NTAPI
CsrCaptureMessageMultiUnicodeStringsInPlace (
	_Inout_ PVOID* CaptureBuffer,
	_In_ ULONG StringsCount,
	_In_ PUNICODE_STRING* MessageStrings
);

NTSYSCALLAPI
NTSTATUS
NTAPI
CsrClientCallServer (
	_Inout_ PBASE_API_MSG ApiMessage,
	_Inout_opt_ PVOID CaptureBuffer,
	_In_ ULONG ApiNumber,
	_In_ ULONG DataLength
);

NTSYSCALLAPI
BOOL
CsrFreeCaptureBuffer (
	_In_ PCSR_CAPTURE_BUFFER captureBuffer
);



_Must_inspect_result_
_When_ (return == 0, __drv_allocatesMem (mem))
NTSYSCALLAPI
NTSTATUS
NTAPI
NtAllocateVirtualMemory (
	_In_ HANDLE ProcessHandle,
	_Inout_ _At_ (*BaseAddress, _Readable_bytes_ (*RegionSize) _Writable_bytes_ (*RegionSize) _Post_readable_byte_size_ (*RegionSize)) PVOID *BaseAddress,
	_In_ ULONG_PTR ZeroBits,
	_Inout_ PULONG_PTR RegionSize,
	_In_ ULONG AllocationType,
	_In_ ULONG Protect
);

// win10rs5+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtAllocateVirtualMemoryEx (
	_In_ HANDLE ProcessHandle,
	_Inout_ _At_ (*BaseAddress, _Readable_bytes_ (*RegionSize) _Writable_bytes_ (*RegionSize) _Post_readable_byte_size_ (*RegionSize)) PVOID *BaseAddress,
	_Inout_ PULONG_PTR RegionSize,
	_In_ ULONG AllocationType,
	_In_ ULONG PageProtection,
	_Inout_updates_opt_ (ExtendedParameterCount) PMEM_EXTENDED_PARAMETER ExtendedParameters,
	_In_ ULONG ExtendedParameterCount
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtFreeVirtualMemory (
	_In_ HANDLE ProcessHandle,
	_Inout_ PVOID *BaseAddress,
	_Inout_ PULONG_PTR RegionSize,
	_In_ ULONG FreeType
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtFlushVirtualMemory (
	_In_ HANDLE ProcessHandle,
	_Inout_ PVOID *BaseAddress,
	_Inout_ PULONG_PTR RegionSize,
	_Out_ PIO_STATUS_BLOCK IoStatus
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtReadVirtualMemory (
	_In_ HANDLE ProcessHandle,
	_In_opt_ PVOID BaseAddress,
	_Out_writes_bytes_ (BufferSize) PVOID Buffer,
	_In_ ULONG_PTR BufferSize,
	_Out_opt_ PULONG_PTR NumberOfBytesRead
);

// win11+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtReadVirtualMemoryEx (
	_In_ HANDLE ProcessHandle,
	_In_opt_ PVOID BaseAddress,
	_Out_writes_bytes_ (BufferSize) PVOID Buffer,
	_In_ ULONG_PTR BufferSize,
	_Out_opt_ PULONG_PTR NumberOfBytesRead,
	_In_ ULONG Flags
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtWriteVirtualMemory (
	_In_ HANDLE ProcessHandle,
	_In_opt_ PVOID BaseAddress,
	_In_reads_bytes_ (BufferSize) PVOID Buffer,
	_In_ ULONG_PTR BufferSize,
	_Out_opt_ PULONG_PTR NumberOfBytesWritten
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtProtectVirtualMemory (
	_In_ HANDLE ProcessHandle,
	_Inout_ PVOID *BaseAddress,
	_Inout_ PULONG_PTR RegionSize,
	_In_ ULONG NewProtect,
	_Out_ PULONG OldProtect
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryVirtualMemory (
	_In_ HANDLE ProcessHandle,
	_In_opt_ PVOID BaseAddress,
	_In_ MEMORY_INFORMATION_CLASS MemoryInformationClass,
	_Out_writes_bytes_ (MemoryInformationLength) PVOID MemoryInformation,
	_In_ ULONG_PTR MemoryInformationLength,
	_Out_opt_ PULONG_PTR ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtLockVirtualMemory (
	_In_ HANDLE ProcessHandle,
	_Inout_ PVOID *BaseAddress,
	_Inout_ PULONG_PTR RegionSize,
	_In_ ULONG MapType
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtUnlockVirtualMemory (
	_In_ HANDLE ProcessHandle,
	_Inout_ PVOID *BaseAddress,
	_Inout_ PULONG_PTR RegionSize,
	_In_ ULONG MapType
);

NTSYSCALLAPI
NTSTATUS
NTAPI
LdrSetDllDirectory (
	_In_ PUNICODE_STRING DllDirectory
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlSetSearchPathMode (
	_In_ ULONG Flags
);

NTSYSCALLAPI
NTSTATUS
NTAPI
LdrSetDefaultDllDirectories (
	_In_ ULONG DirectoryFlags
);

NTSYSCALLAPI
VOID
NTAPI
RtlTimeToTimeFields (
	_In_ PLARGE_INTEGER Time,
	_Out_ PTIME_FIELDS TimeFields
);

NTSYSCALLAPI
BOOLEAN
NTAPI
RtlTimeFieldsToTime (
	_In_ PTIME_FIELDS TimeFields, // Weekday is ignored
	_Out_ PLARGE_INTEGER Time
);

NTSYSCALLAPI
NTSTATUS
NTAPI
LdrLoadDll (
	_In_opt_ PWSTR DllPath,
	_In_opt_ PULONG DllCharacteristics,
	_In_ PUNICODE_STRING DllName,
	_Out_ PVOID *DllHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
LdrUnloadDll (
	_In_ PVOID DllHandle
);

#define LDR_GET_PROCEDURE_ADDRESS_DONT_RECORD_FORWARDER 0x00000001

// vista+
NTSYSCALLAPI
NTSTATUS
NTAPI
LdrGetProcedureAddressEx (
	_In_ PVOID DllHandle,
	_In_opt_ PANSI_STRING ProcedureName,
	_In_opt_ ULONG ProcedureNumber,
	_Out_ PVOID *ProcedureAddress,
	_In_ ULONG Flags
);

NTSYSCALLAPI
NTSTATUS
NTAPI
LdrGetDllFullName (
	_In_ PVOID DllHandle,
	_Out_ PUNICODE_STRING FullDllName
);

NTSYSCALLAPI
NTSTATUS
NTAPI
LdrGetDllHandleEx (
	_In_ ULONG Flags,
	_In_opt_ PWSTR DllPath,
	_In_opt_ PULONG DllCharacteristics,
	_In_ PUNICODE_STRING DllName,
	_Out_ PVOID *DllHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
LdrGetDllPath (
	_In_ PCWSTR DllName,
	_In_ ULONG Flags, // LOAD_LIBRARY_SEARCH_*
	_Out_ PWSTR *DllPath,
	_Out_ PWSTR *SearchPaths
);

NTSYSCALLAPI
VOID
NTAPI
RtlReleasePath (
	_In_ PWSTR Path
);

NTSYSCALLAPI
NTSTATUS
NTAPI
LdrAccessResource (
	_In_ PVOID DllHandle,
	_In_ PIMAGE_RESOURCE_DATA_ENTRY ResourceDataEntry,
	_Out_opt_ PVOID *ResourceBuffer,
	_Out_opt_ PULONG ResourceLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
LdrFindResource_U (
	_In_ PVOID DllHandle,
	_In_ PLDR_RESOURCE_INFO ResourceInfo,
	_In_ ULONG Level,
	_Out_ PIMAGE_RESOURCE_DATA_ENTRY *ResourceDataEntry
);

NTSYSCALLAPI
LONG
WINAPI
GetStagedPackagePathByFullName (
	_In_ PCWSTR packageFullName,
	_Inout_ PUINT32 pathLength,
	_Out_opt_ PWSTR path
);

NTSYSCALLAPI
NTSTATUS
WINAPI
NtQueryDefaultLocale (
	_In_ BOOLEAN UserProfile,
	_Inout_ PLCID DefaultLocaleId
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlConvertLCIDToString (
	_In_ LCID LcidValue,
	_In_ ULONG Base,
	_In_ ULONG Padding, // string is padded to this width
	_Out_writes_ (Size) PWSTR pResultBuf,
	_In_ ULONG Size
);

NTSYSCALLAPI
BOOLEAN
NTAPI
RtlIsValidLocaleName (
	_In_ PCWSTR LocaleName,
	_In_ ULONG Flags
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlLcidToLocaleName (
	_In_ LCID lcid, // sic
	_Inout_ PUNICODE_STRING LocaleName,
	_In_ ULONG Flags,
	_In_ BOOLEAN AllocateDestinationString
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlLocaleNameToLcid (
	_In_ PCWSTR LocaleName,
	_Out_ PLCID lcid,
	_In_ ULONG Flags
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlpGetSystemDefaultUILanguage (
	_Out_ LANGID DefaultUILanguageId,
	_Inout_ PLCID Lcid
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetUserPreferredUILanguages (
	_In_ ULONG Flags, // MUI_LANGUAGE_NAME
	_In_ PCWSTR LocaleName,
	_Out_ PULONG NumberOfLanguages,
	_Out_writes_opt_ (*ReturnLength) PZZWSTR Languages,
	_Inout_ PULONG ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetUILanguageInfo (
	_In_ ULONG Flags,
	_In_ PCZZWSTR Languages,
	_Out_writes_opt_ (*NumberOfFallbackLanguages) PZZWSTR FallbackLanguages,
	_Inout_opt_ PULONG NumberOfFallbackLanguages,
	_Out_ PULONG Attributes
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetLocaleFileMappingAddress (
	_Out_ PVOID *BaseAddress,
	_Out_ PLCID DefaultLocaleId,
	_Out_ PLARGE_INTEGER DefaultCasingTableSize,
	_Out_opt_ PULONG CurrentNLSVersion
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlCreateUserThread (
	_In_ HANDLE Process,
	_In_opt_ PSECURITY_DESCRIPTOR ThreadSecurityDescriptor,
	_In_ BOOLEAN CreateSuspended,
	_In_opt_ ULONG ZeroBits,
	_In_opt_ ULONG_PTR MaximumStackSize,
	_In_opt_ ULONG_PTR CommittedStackSize,
	_In_ PUSER_THREAD_START_ROUTINE StartAddress,
	_In_opt_ PVOID Parameter,
	_Out_opt_ PHANDLE Thread,
	_Out_opt_ PCLIENT_ID ClientId
);

DECLSPEC_NORETURN
NTSYSCALLAPI
VOID
NTAPI
RtlExitUserThread (
	_In_ NTSTATUS ExitStatus
);

DECLSPEC_NORETURN
NTSYSCALLAPI
VOID
NTAPI
RtlExitUserProcess (
	_In_ NTSTATUS ExitStatus
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenThread (
	_Out_ PHANDLE ThreadHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_opt_ PCLIENT_ID ClientId
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtTerminateThread (
	_In_opt_ HANDLE ThreadHandle,
	_In_ NTSTATUS ExitStatus
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSuspendThread (
	_In_ HANDLE ThreadHandle,
	_Out_opt_ PULONG PreviousSuspendCount
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtResumeThread (
	_In_ HANDLE ThreadHandle,
	_Out_opt_ PULONG PreviousSuspendCount
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtGetContextThread (
	_In_ HANDLE ThreadHandle,
	_Inout_ PCONTEXT ThreadContext
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetContextThread (
	_In_ HANDLE ThreadHandle,
	_In_ PCONTEXT ThreadContext
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryInformationThread (
	_In_ HANDLE ThreadHandle,
	_In_ THREADINFOCLASS ThreadInformationClass,
	_Out_writes_bytes_ (ThreadInformationLength) PVOID ThreadInformation,
	_In_ ULONG ThreadInformationLength,
	_Out_opt_ PULONG ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetInformationThread (
	_In_ HANDLE ThreadHandle,
	_In_ THREADINFOCLASS ThreadInformationClass,
	_In_reads_bytes_ (ThreadInformationLength) PVOID ThreadInformation,
	_In_ ULONG ThreadInformationLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtAlertThread (
	_In_ HANDLE ThreadHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtAlertResumeThread (
	_In_ HANDLE ThreadHandle,
	_Out_opt_ PULONG PreviousSuspendCount
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtTestAlert (
	VOID
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtImpersonateThread (
	_In_ HANDLE ServerThreadHandle,
	_In_ HANDLE ClientThreadHandle,
	_In_ PSECURITY_QUALITY_OF_SERVICE SecurityQos
);

NTSYSCALLAPI
PVOID
NTAPI
RtlCreateHeap (
	_In_ ULONG Flags,
	_In_opt_ PVOID HeapBase,
	_In_opt_ ULONG_PTR ReserveSize,
	_In_opt_ ULONG_PTR CommitSize,
	_In_opt_ PVOID Lock,
	_In_opt_ PRTL_HEAP_PARAMETERS Parameters
);

NTSYSCALLAPI
PVOID
NTAPI
RtlDestroyHeap (
	_In_ _Post_invalid_ PVOID HeapHandle
);

NTSYSCALLAPI
PVOID
NTAPI
RtlAllocateHeap (
	_In_ PVOID HeapHandle,
	_In_opt_ ULONG Flags,
	_In_ ULONG_PTR Size
);

NTSYSCALLAPI
PVOID
NTAPI
RtlReAllocateHeap (
	_In_ PVOID HeapHandle,
	_In_ ULONG Flags,
	_Frees_ptr_opt_ PVOID BaseAddress,
	_In_ ULONG_PTR Size
);

NTSYSCALLAPI
BOOLEAN
NTAPI
RtlFreeHeap (
	_In_ PVOID HeapHandle,
	_In_opt_ ULONG Flags,
	_Frees_ptr_opt_ PVOID BaseAddress
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlSetHeapInformation (
	_In_ PVOID HeapHandle,
	_In_ HEAP_INFORMATION_CLASS HeapInformationClass,
	_In_opt_ PVOID HeapInformation,
	_In_opt_ ULONG_PTR HeapInformationLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlFindMessage (
	_In_ PVOID DllHandle,
	_In_ ULONG MessageTableId,
	_In_ ULONG MessageLanguageId,
	_In_ ULONG MessageId,
	_Out_ PMESSAGE_RESOURCE_ENTRY *MessageEntry
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtDelayExecution (
	_In_ BOOLEAN Alertable,
	_In_opt_ PLARGE_INTEGER DelayInterval
);

// win10+
NTSYSCALLAPI
NTSTATUS
NTAPI
RtlDelayExecution (
	_In_ BOOLEAN Alertable,
	_In_opt_ PLARGE_INTEGER DelayInterval
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQuerySystemEnvironmentValue (
	_In_ PUNICODE_STRING VariableName,
	_Out_writes_bytes_ (ValueLength) PWSTR VariableValue,
	_In_ USHORT ValueLength,
	_Out_opt_ PUSHORT ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQuerySystemEnvironmentValueEx (
	_In_ PUNICODE_STRING VariableName,
	_In_ LPCGUID VendorGuid,
	_Out_writes_bytes_opt_ (*ValueLength) PVOID Value,
	_Inout_ PULONG ValueLength,
	_Out_opt_ PULONG Attributes // EFI_VARIABLE_*
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetSystemEnvironmentValueEx (
	_In_ PUNICODE_STRING VariableName,
	_In_ LPCGUID VendorGuid,
	_In_reads_bytes_opt_ (ValueLength) PVOID Value,
	_In_ ULONG ValueLength, // 0 = delete variable
	_In_ ULONG Attributes // EFI_VARIABLE_*
);


NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetSystemEnvironmentValue (
	_In_ PUNICODE_STRING VariableName,
	_In_ PUNICODE_STRING VariableValue
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryObject (
	_In_opt_ HANDLE Handle,
	_In_ OBJECT_INFORMATION_CLASS ObjectInformationClass,
	_Out_writes_bytes_opt_ (ObjectInformationLength) PVOID ObjectInformation,
	_In_ ULONG ObjectInformationLength,
	_Out_opt_ PULONG ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetSystemInformation (
	_In_ SYSTEM_INFORMATION_CLASS SystemInformationClass,
	_In_reads_bytes_opt_ (SystemInformationLength) PVOID SystemInformation,
	_In_ ULONG SystemInformationLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQuerySystemInformation (
	_In_ SYSTEM_INFORMATION_CLASS SystemInformationClass,
	_Out_writes_bytes_opt_ (SystemInformationLength) PVOID SystemInformation,
	_In_ ULONG SystemInformationLength,
	_Out_opt_ PULONG ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
TpAllocTimer (
	_Out_ PTP_TIMER * Timer,
	_In_ PTP_TIMER_CALLBACK Callback,
	_Inout_opt_ PVOID Context,
	_In_opt_ PTP_CALLBACK_ENVIRON CallbackEnviron
);

NTSYSCALLAPI
VOID
NTAPI
TpReleaseTimer (
	_Inout_ PTP_TIMER Timer
);

NTSYSCALLAPI
VOID
NTAPI
TpSetTimer (
	_Inout_ PTP_TIMER Timer,
	_In_opt_ PLARGE_INTEGER DueTime,
	_In_ ULONG Period,
	_In_opt_ ULONG WindowLength
);

// win8+
NTSYSCALLAPI
NTSTATUS
NTAPI
TpSetTimerEx (
	_Inout_ PTP_TIMER Timer,
	_In_opt_ PLARGE_INTEGER DueTime,
	_In_ ULONG Period,
	_In_opt_ ULONG WindowLength
);

NTSYSCALLAPI
VOID
NTAPI
TpWaitForTimer (
	_Inout_ PTP_TIMER Timer,
	_In_ LOGICAL CancelPendingCallbacks
);

NTSYSCALLAPI
LOGICAL
NTAPI
TpIsTimerSet (
	_In_ PTP_TIMER Timer
);

// vista+
NTSYSCALLAPI
NTSTATUS
NTAPI
RtlCreateProcessParametersEx (
	_Out_ PRTL_USER_PROCESS_PARAMETERS *pProcessParameters,
	_In_ PUNICODE_STRING ImagePathName,
	_In_opt_ PUNICODE_STRING DllPath,
	_In_opt_ PUNICODE_STRING CurrentDirectory,
	_In_opt_ PUNICODE_STRING CommandLine,
	_In_opt_ PVOID Environment,
	_In_opt_ PUNICODE_STRING WindowTitle,
	_In_opt_ PUNICODE_STRING DesktopInfo,
	_In_opt_ PUNICODE_STRING ShellInfo,
	_In_opt_ PUNICODE_STRING RuntimeData,
	_In_ ULONG Flags // pass RTL_USER_PROC_PARAMS_NORMALIZED to keep parameters normalized
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlDestroyProcessParameters (
	_In_ _Post_invalid_ PRTL_USER_PROCESS_PARAMETERS ProcessParameters
);

// vista+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateUserProcess (
	_Out_ PHANDLE ProcessHandle,
	_Out_ PHANDLE ThreadHandle,
	_In_ ACCESS_MASK ProcessDesiredAccess,
	_In_ ACCESS_MASK ThreadDesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ProcessObjectAttributes,
	_In_opt_ POBJECT_ATTRIBUTES ThreadObjectAttributes,
	_In_ ULONG ProcessFlags, // PROCESS_CREATE_FLAGS_*
	_In_ ULONG ThreadFlags, // THREAD_CREATE_FLAGS_*
	_In_opt_ PVOID ProcessParameters, // PRTL_USER_PROCESS_PARAMETERS
	_Inout_ PPS_CREATE_INFO CreateInfo,
	_In_opt_ PPS_ATTRIBUTE_LIST AttributeList
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenProcess (
	_Out_ PHANDLE ProcessHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_opt_ PCLIENT_ID ClientId
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenProcessToken (
	_In_ HANDLE ProcessHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_Out_ PHANDLE TokenHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenProcessTokenEx (
	_In_ HANDLE ProcessHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ ULONG HandleAttributes,
	_Out_ PHANDLE TokenHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtTerminateProcess (
	_In_opt_ HANDLE ProcessHandle,
	_In_ NTSTATUS ExitStatus
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSuspendProcess (
	_In_ HANDLE ProcessHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtResumeProcess (
	_In_ HANDLE ProcessHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetInformationProcess (
	_In_ HANDLE ProcessHandle,
	_In_ PROCESSINFOCLASS ProcessInformationClass,
	_In_reads_bytes_ (ProcessInformationLength) PVOID ProcessInformation,
	_In_ ULONG ProcessInformationLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryInformationProcess (
	_In_ HANDLE ProcessHandle,
	_In_ PROCESSINFOCLASS ProcessInformationClass,
	_Out_writes_bytes_ (ProcessInformationLength) PVOID ProcessInformation,
	_In_ ULONG ProcessInformationLength,
	_Out_opt_ PULONG ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenSymbolicLinkObject (
	_Out_ PHANDLE LinkHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQuerySymbolicLinkObject (
	_In_ HANDLE LinkHandle,
	_Inout_ PUNICODE_STRING LinkTarget,
	_Out_opt_ PULONG ReturnedLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateToken (
	_Out_ PHANDLE TokenHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_ TOKEN_TYPE TokenType,
	_In_ PLUID AuthenticationId,
	_In_ PLARGE_INTEGER ExpirationTime,
	_In_ PTOKEN_USER User,
	_In_ PTOKEN_GROUPS Groups,
	_In_ PTOKEN_PRIVILEGES Privileges,
	_In_opt_ PTOKEN_OWNER Owner,
	_In_ PTOKEN_PRIMARY_GROUP PrimaryGroup,
	_In_opt_ PTOKEN_DEFAULT_DACL DefaultDacl,
	_In_ PTOKEN_SOURCE TokenSource
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenProcessTokenEx (
	_In_ HANDLE ProcessHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ ULONG HandleAttributes,
	_Out_ PHANDLE TokenHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenThreadToken (
	_In_ HANDLE ThreadHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ BOOLEAN OpenAsSelf,
	_Out_ PHANDLE TokenHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenThreadTokenEx (
	_In_ HANDLE ThreadHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ BOOLEAN OpenAsSelf,
	_In_ ULONG HandleAttributes,
	_Out_ PHANDLE TokenHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtDuplicateToken (
	_In_ HANDLE ExistingTokenHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_ BOOLEAN EffectiveOnly,
	_In_ TOKEN_TYPE Type,
	_Out_ PHANDLE NewTokenHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryInformationToken (
	_In_ HANDLE TokenHandle,
	_In_ TOKEN_INFORMATION_CLASS TokenInformationClass,
	_Out_writes_bytes_to_opt_ (TokenInformationLength, *ReturnLength) PVOID TokenInformation,
	_In_ ULONG TokenInformationLength,
	_Out_ PULONG ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetInformationToken (
	_In_ HANDLE TokenHandle,
	_In_ TOKEN_INFORMATION_CLASS TokenInformationClass,
	_In_reads_bytes_ (TokenInformationLength) PVOID TokenInformation,
	_In_ ULONG TokenInformationLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtAdjustPrivilegesToken (
	_In_ HANDLE TokenHandle,
	_In_ BOOLEAN DisableAllPrivileges,
	_In_opt_ PTOKEN_PRIVILEGES NewState,
	_In_ ULONG BufferLength,
	_Out_writes_bytes_to_opt_ (BufferLength, *ReturnLength) PTOKEN_PRIVILEGES PreviousState,
	_Out_opt_ PULONG ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtPrivilegeCheck (
	_In_ HANDLE ClientToken,
	_Inout_ PPRIVILEGE_SET RequiredPrivileges,
	_Out_ PBOOLEAN Result
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtImpersonateAnonymousToken (
	_In_ HANDLE ThreadHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateDirectoryObject (
	_Out_ PHANDLE DirectoryHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtDeviceIoControlFile (
	_In_ HANDLE FileHandle,
	_In_opt_ HANDLE Event,
	_In_opt_ PIO_APC_ROUTINE ApcRoutine,
	_In_opt_ PVOID ApcContext,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_In_ ULONG IoControlCode,
	_In_reads_bytes_opt_ (InputBufferLength) PVOID InputBuffer,
	_In_ ULONG InputBufferLength,
	_Out_writes_bytes_opt_ (OutputBufferLength) PVOID OutputBuffer,
	_In_ ULONG OutputBufferLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtFsControlFile (
	_In_ HANDLE FileHandle,
	_In_opt_ HANDLE Event,
	_In_opt_ PIO_APC_ROUTINE ApcRoutine,
	_In_opt_ PVOID ApcContext,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_In_ ULONG FsControlCode,
	_In_reads_bytes_opt_ (InputBufferLength) PVOID InputBuffer,
	_In_ ULONG InputBufferLength,
	_Out_writes_bytes_opt_ (OutputBufferLength) PVOID OutputBuffer,
	_In_ ULONG OutputBufferLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateFile (
	_Out_ PHANDLE FileHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_In_opt_ PLARGE_INTEGER AllocationSize,
	_In_ ULONG FileAttributes,
	_In_ ULONG ShareAccess,
	_In_ ULONG CreateDisposition,
	_In_ ULONG CreateOptions,
	_In_reads_bytes_opt_ (EaLength) PVOID EaBuffer,
	_In_ ULONG EaLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenFile (
	_Out_ PHANDLE FileHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_In_ ULONG ShareAccess,
	_In_ ULONG OpenOptions
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtReadFile (
	_In_ HANDLE FileHandle,
	_In_opt_ HANDLE Event,
	_In_opt_ PVOID ApcRoutine,
	_In_opt_ PVOID ApcContext,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_Out_writes_bytes_ (Length) PVOID Buffer,
	_In_ ULONG Length,
	_In_opt_ PLARGE_INTEGER ByteOffset,
	_In_opt_ PULONG Key
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtWriteFile (
	_In_ HANDLE FileHandle,
	_In_opt_ HANDLE Event,
	_In_opt_ PVOID ApcRoutine,
	_In_opt_ PVOID ApcContext,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_In_reads_bytes_ (Length) PVOID Buffer,
	_In_ ULONG Length,
	_In_opt_ PLARGE_INTEGER ByteOffset,
	_In_opt_ PULONG Key
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtDeleteFile (
	_In_ POBJECT_ATTRIBUTES ObjectAttributes
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtFlushBuffersFile (
	_In_ HANDLE FileHandle,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryInformationFile (
	_In_ HANDLE FileHandle,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_Out_writes_bytes_ (Length) PVOID FileInformation,
	_In_ ULONG Length,
	_In_ FILE_INFORMATION_CLASS FileInformationClass
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryAttributesFile (
	_In_ POBJECT_ATTRIBUTES ObjectAttributes,
	_Out_ PFILE_BASIC_INFORMATION FileInformation
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetInformationFile (
	_In_ HANDLE FileHandle,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_In_reads_bytes_ (Length) PVOID FileInformation,
	_In_ ULONG Length,
	_In_ FILE_INFORMATION_CLASS FileInformationClass
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryDirectoryFile (
	_In_ HANDLE FileHandle,
	_In_opt_ HANDLE Event,
	_In_opt_ PIO_APC_ROUTINE ApcRoutine,
	_In_opt_ PVOID ApcContext,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_Out_writes_bytes_ (Length) PVOID FileInformation,
	_In_ ULONG Length,
	_In_ FILE_INFORMATION_CLASS FileInformationClass,
	_In_ BOOLEAN ReturnSingleEntry,
	_In_opt_ PUNICODE_STRING FileName,
	_In_ BOOLEAN RestartScan
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtClose (
	_In_ _Post_ptr_invalid_ HANDLE Handle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryVolumeInformationFile (
	_In_ HANDLE FileHandle,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_Out_writes_bytes_ (Length) PVOID FsInformation,
	_In_ ULONG Length,
	_In_ FSINFOCLASS FsInformationClass
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetVolumeInformationFile (
	_In_ HANDLE FileHandle,
	_Out_ PIO_STATUS_BLOCK IoStatusBlock,
	_In_reads_bytes_ (Length) PVOID FsInformation,
	_In_ ULONG Length,
	_In_ FSINFOCLASS FsInformationClass
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetVersion (
	_Out_ PRTL_OSVERSIONINFOEXW VersionInformation // PRTL_OSVERSIONINFOW
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateIoCompletion(
	_Out_ PHANDLE IoCompletionHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_opt_ ULONG Count
);

#define RTL_DOS_SEARCH_PATH_FLAG_APPLY_ISOLATION_REDIRECTION 0x00000001
#define RTL_DOS_SEARCH_PATH_FLAG_DISALLOW_DOT_RELATIVE_PATH_SEARCH 0x00000002
#define RTL_DOS_SEARCH_PATH_FLAG_APPLY_DEFAULT_EXTENSION_WHEN_NOT_RELATIVE_PATH_EVEN_IF_FILE_HAS_EXTENSION 0x00000004

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlDosSearchPath_Ustr (
	_In_ ULONG Flags,
	_In_ PUNICODE_STRING Path,
	_In_ PUNICODE_STRING FileName,
	_In_opt_ PUNICODE_STRING DefaultExtension,
	_Out_opt_ PUNICODE_STRING StaticString,
	_Out_opt_ PUNICODE_STRING DynamicString,
	_Out_opt_ PCUNICODE_STRING *FullFileNameOut,
	_Out_opt_ PULONG_PTR FilePartPrefixCch,
	_Out_opt_ PULONG_PTR BytesRequired
);

NTSYSCALLAPI
BOOLEAN
NTAPI
RtlDoesFileExists_U (
	_In_ PCWSTR FileName
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetSearchPath (
	_Out_ PWSTR *SearchPath
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetFullPathName_UEx (
	_In_ PCWSTR FileName,
	_In_ ULONG BufferLength,
	_Out_writes_bytes_ (BufferLength) PWSTR Buffer,
	_Out_opt_ PWSTR *FilePart,
	_Out_opt_ PULONG BytesRequired
);

NTSYSCALLAPI
ULONG
NTAPI
RtlGetCurrentDirectory_U (
	_In_ ULONG BufferLength,
	_Out_writes_bytes_ (BufferLength) PWSTR Buffer
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlSetCurrentDirectory_U (
	_In_ PUNICODE_STRING PathName
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlDosPathNameToNtPathName_U_WithStatus (
	_In_ PCWSTR DosFileName,
	_Out_ PUNICODE_STRING NtFileName,
	_Out_opt_ PWSTR *FilePart,
	_Out_opt_ PRTL_RELATIVE_NAME_U RelativeName
);

// server2003+
NTSYSCALLAPI
VOID
NTAPI
RtlReleaseRelativeName (
	_Inout_ PRTL_RELATIVE_NAME_U RelativeName
);

NTSYSCALLAPI
VOID
NTAPI
RtlInitAnsiString (
	_Out_ PANSI_STRING DestinationString,
	_In_opt_ PCSTR SourceString
);

NTSYSCALLAPI
VOID
NTAPI
RtlInitUnicodeString (
	_Out_ PUNICODE_STRING DestinationString,
	_In_opt_z_ PCWSTR SourceString
);

NTSYSCALLAPI
VOID
NTAPI
RtlFreeUnicodeString (
	_In_ PUNICODE_STRING UnicodeString
);

NTSYSCALLAPI
WCHAR
NTAPI
RtlUpcaseUnicodeChar (
	_In_ WCHAR SourceCharacter
);

NTSYSCALLAPI
WCHAR
NTAPI
RtlDowncaseUnicodeChar (
	_In_ WCHAR SourceCharacter
);

// win81+
NTSYSCALLAPI
NTSTATUS
NTAPI
RtlStringFromGUIDEx (
	_In_ LPGUID Guid,
	_Inout_ PUNICODE_STRING GuidString,
	_In_ BOOLEAN AllocateGuidString
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGUIDFromString (
	_In_ PUNICODE_STRING GuidString,
	_Out_ LPGUID Guid
);

// win vista+
NTSYSCALLAPI
NTSTATUS
NTAPI
RtlCreateServiceSid (
	_In_ PUNICODE_STRING ServiceName,
	_Out_writes_bytes_opt_ (*ServiceSidLength) PSID ServiceSid,
	_Inout_ PULONG ServiceSidLength
);

NTSYSCALLAPI
PULONG
NTAPI
RtlSubAuthoritySid (
	_In_ PSID Sid,
	_In_ ULONG SubAuthority
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlConvertSidToUnicodeString (
	_Inout_ PUNICODE_STRING UnicodeString,
	_In_ PSID Sid,
	_In_ BOOLEAN AllocateDestinationString
);

_Must_inspect_result_
NTSYSCALLAPI
BOOLEAN
NTAPI
RtlValidSid (
	_In_ PSID Sid
);

_Must_inspect_result_
NTSYSCALLAPI
BOOLEAN
NTAPI
RtlEqualSid (
	_In_ PSID Sid1,
	_In_ PSID Sid2
);

NTSYSCALLAPI
ULONG
NTAPI
RtlLengthSid (
	_In_ PSID Sid
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlCreateSecurityDescriptor (
	_Out_ PSECURITY_DESCRIPTOR SecurityDescriptor,
	_In_ ULONG Revision
);

NTSYSCALLAPI
BOOLEAN
NTAPI
RtlValidSecurityDescriptor (
	_In_ PSECURITY_DESCRIPTOR SecurityDescriptor
);

NTSYSCALLAPI
ULONG
NTAPI
RtlLengthSecurityDescriptor (
	_In_ PSECURITY_DESCRIPTOR SecurityDescriptor
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetOwnerSecurityDescriptor (
	_In_ PSECURITY_DESCRIPTOR SecurityDescriptor,
	_Outptr_result_maybenull_ PSID *Owner,
	_Out_ PBOOLEAN OwnerDefaulted
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlMakeSelfRelativeSD (
	_In_ PSECURITY_DESCRIPTOR AbsoluteSecurityDescriptor,
	_Out_writes_bytes_ (*BufferLength) PSECURITY_DESCRIPTOR SelfRelativeSecurityDescriptor,
	_Inout_ PULONG BufferLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlAddAce (
	_Inout_ PACL Acl,
	_In_ ULONG AceRevision,
	_In_ ULONG StartingAceIndex,
	_In_reads_bytes_ (AceListLength) PVOID AceList,
	_In_ ULONG AceListLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlDeleteAce (
	_Inout_ PACL Acl,
	_In_ ULONG AceIndex
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetAce (
	_In_ PACL Acl,
	_In_ ULONG AceIndex,
	_Outptr_ PVOID *Ace
);

NTSYSCALLAPI
ULONG
NTAPI
RtlRandomEx (
	_Inout_ PULONG Seed
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlUnicodeToMultiByteSize (
	_Out_ PULONG BytesInMultiByteString,
	_In_reads_bytes_ (BytesInUnicodeString) PCWCH UnicodeString,
	_In_ ULONG BytesInUnicodeString
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlUnicodeToMultiByteN (
	_Out_writes_bytes_to_ (MaxBytesInMultiByteString, *BytesInMultiByteString) PCHAR MultiByteString,
	_In_ ULONG MaxBytesInMultiByteString,
	_Out_opt_ PULONG BytesInMultiByteString,
	_In_reads_bytes_ (BytesInUnicodeString) PCWCH UnicodeString,
	_In_ ULONG BytesInUnicodeString
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlMultiByteToUnicodeSize (
	_Out_ PULONG BytesInUnicodeString,
	_In_reads_bytes_ (BytesInMultiByteString) PCSTR MultiByteString,
	_In_ ULONG BytesInMultiByteString
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlMultiByteToUnicodeN (
	_Out_writes_bytes_to_ (MaxBytesInUnicodeString, *BytesInUnicodeString) PWCH UnicodeString,
	_In_ ULONG MaxBytesInUnicodeString,
	_Out_opt_ PULONG BytesInUnicodeString,
	_In_reads_bytes_ (BytesInMultiByteString) PCSTR MultiByteString,
	_In_ ULONG BytesInMultiByteString
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlUTF8ToUnicodeN (
	_Out_writes_bytes_to_ (UnicodeStringMaxByteCount, *UnicodeStringActualByteCount) PWSTR UnicodeStringDestination,
	_In_ ULONG UnicodeStringMaxByteCount,
	_Out_opt_ PULONG UnicodeStringActualByteCount,
	_In_reads_bytes_ (UTF8StringByteCount) PCCH UTF8StringSource,
	_In_ ULONG UTF8StringByteCount
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlUnicodeToUTF8N (
	_Out_writes_bytes_to_ (UTF8StringMaxByteCount, *UTF8StringActualByteCount) PCHAR UTF8StringDestination,
	_In_ ULONG UTF8StringMaxByteCount,
	_Out_opt_ PULONG UTF8StringActualByteCount,
	_In_reads_bytes_(UnicodeStringByteCount) PCWCH UnicodeStringSource,
	_In_ ULONG UnicodeStringByteCount
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlExpandEnvironmentStrings_U (
	_In_opt_ PVOID Environment,
	_In_ PUNICODE_STRING Source,
	_Inout_ PUNICODE_STRING Destination,
	_Out_opt_ PULONG ReturnedLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlSetEnvironmentVariable (
	_Inout_opt_ PVOID *Environment,
	_In_ PUNICODE_STRING Name,
	_In_opt_ PUNICODE_STRING Value
);

NTSYSCALLAPI
ULONG
NTAPI
RtlNtStatusToDosError (
	_In_ NTSTATUS Status
);

NTSYSCALLAPI
ULONG
NTAPI
RtlNtStatusToDosErrorNoTeb (
	_In_ NTSTATUS Status
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetLastNtStatus (
	VOID
);

NTSYSCALLAPI
LONG
NTAPI
RtlGetLastWin32Error (
	VOID
);

NTSYSCALLAPI
VOID
NTAPI
RtlSetLastWin32ErrorAndNtStatusFromNtStatus (
	_In_ NTSTATUS Status
);

NTSYSCALLAPI
VOID
NTAPI
RtlSetLastWin32Error (
	_In_ LONG Win32Error
);

NTSYSCALLAPI
VOID
NTAPI
RtlRestoreLastWin32Error (
	_In_ LONG Win32Error
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenDirectoryObject (
	_Out_ PHANDLE DirectoryHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryDirectoryObject (
	_In_ HANDLE DirectoryHandle,
	_Out_writes_bytes_opt_ (Length) PVOID Buffer,
	_In_ ULONG Length,
	_In_ BOOLEAN ReturnSingleEntry,
	_In_ BOOLEAN RestartScan,
	_Inout_ PULONG Context,
	_Out_opt_ PULONG ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateSemaphore (
	_Out_ PHANDLE SemaphoreHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_ LONG InitialCount,
	_In_ LONG MaximumCount
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtReleaseSemaphore (
	_In_ HANDLE SemaphoreHandle,
	_In_ LONG ReleaseCount,
	_Out_opt_ PLONG PreviousCount
);

NTSYSCALLAPI
BOOLEAN
NTAPI
RtlDispatchException (
	_In_ PEXCEPTION_RECORD ExceptionRecord,
	_In_ PCONTEXT ContextRecord
);

NTSYSCALLAPI
DECLSPEC_NORETURN
VOID
NTAPI
RtlRaiseStatus (
	_In_ NTSTATUS Status
);

NTSYSCALLAPI
VOID
NTAPI
RtlRaiseException (
	_In_ PEXCEPTION_RECORD ExceptionRecord
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtContinue (
	_In_ PCONTEXT ContextRecord,
	_In_ BOOLEAN TestAlert
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtRaiseException (
	_In_ PEXCEPTION_RECORD ExceptionRecord,
	_In_ PCONTEXT ContextRecord,
	_In_ BOOLEAN FirstChance
);

__analysis_noreturn
NTSYSCALLAPI
VOID
NTAPI
RtlAssert (
	_In_ PVOID VoidFailedAssertion,
	_In_ PVOID VoidFileName,
	_In_ ULONG LineNumber,
	_In_opt_ PSTR MutableMessage
);

// Vectored Exception Handlers

NTSYSCALLAPI
PVOID
NTAPI
RtlAddVectoredExceptionHandler (
	_In_ ULONG First,
	_In_ PVECTORED_EXCEPTION_HANDLER Handler
);

NTSYSCALLAPI
ULONG
NTAPI
RtlRemoveVectoredExceptionHandler (
	_In_ PVOID Handle
);

NTSYSCALLAPI
PVOID
NTAPI
RtlAddVectoredContinueHandler (
	_In_ ULONG First,
	_In_ PVECTORED_EXCEPTION_HANDLER Handler
);

NTSYSCALLAPI
ULONG
NTAPI
RtlRemoveVectoredContinueHandler (
	_In_ PVOID Handle
);

// Runtime exception handling

typedef ULONG (NTAPI *PRTLP_UNHANDLED_EXCEPTION_FILTER)(
	_In_ PEXCEPTION_POINTERS ExceptionInfo
	);

// vista+
NTSYSCALLAPI
VOID
NTAPI
RtlSetUnhandledExceptionFilter (
	_In_ PRTLP_UNHANDLED_EXCEPTION_FILTER UnhandledExceptionFilter
);

// rev
NTSYSCALLAPI
LONG
NTAPI
RtlUnhandledExceptionFilter (
	_In_ PEXCEPTION_POINTERS ExceptionPointers
);

// rev
NTSYSCALLAPI
LONG
NTAPI
RtlUnhandledExceptionFilter2 (
	_In_ PEXCEPTION_POINTERS ExceptionPointers,
	_In_ ULONG Flags
);

// rev
NTSYSCALLAPI
LONG
NTAPI
RtlKnownExceptionFilter (
	_In_ PEXCEPTION_POINTERS ExceptionPointers
);

// winbase:InitializeSRWLock
NTSYSCALLAPI
VOID
NTAPI
RtlInitializeSRWLock (
	_Out_ PRTL_SRWLOCK SRWLock
);

// winbase:AcquireSRWLockExclusive
NTSYSCALLAPI
VOID
NTAPI
RtlAcquireSRWLockExclusive (
	_Inout_ PRTL_SRWLOCK SRWLock
);

// winbase:AcquireSRWLockShared
NTSYSCALLAPI
VOID
NTAPI
RtlAcquireSRWLockShared (
	_Inout_ PRTL_SRWLOCK SRWLock
);

// winbase:ReleaseSRWLockExclusive
NTSYSCALLAPI
VOID
NTAPI
RtlReleaseSRWLockExclusive (
	_Inout_ PRTL_SRWLOCK SRWLock
);

// winbase:ReleaseSRWLockShared
NTSYSCALLAPI
VOID
NTAPI
RtlReleaseSRWLockShared (
	_Inout_ PRTL_SRWLOCK SRWLock
);

// winbase:TryAcquireSRWLockExclusive
NTSYSCALLAPI
BOOLEAN
NTAPI
RtlTryAcquireSRWLockExclusive (
	_Inout_ PRTL_SRWLOCK SRWLock
);

// winbase:TryAcquireSRWLockShared
NTSYSCALLAPI
BOOLEAN
NTAPI
RtlTryAcquireSRWLockShared (
	_Inout_ PRTL_SRWLOCK SRWLock
);

_Acquires_exclusive_lock_ (*CriticalSection)
NTSYSCALLAPI
NTSTATUS
NTAPI
RtlEnterCriticalSection (
	_Inout_ PRTL_CRITICAL_SECTION CriticalSection
);

_Releases_exclusive_lock_ (*CriticalSection)
NTSYSCALLAPI
NTSTATUS
NTAPI
RtlLeaveCriticalSection (
	_Inout_ PRTL_CRITICAL_SECTION CriticalSection
);

NTSYSCALLAPI
PPEB
NTAPI
RtlGetCurrentPeb (
	VOID
);

NTSYSCALLAPI
VOID
RtlAcquirePebLock (
	VOID
);

NTSYSCALLAPI
VOID
RtlReleasePebLock (
	VOID
);

NTSYSCALLAPI
NTSTATUS
RtlRunOnceBeginInitialize (
	_Inout_ PRTL_RUN_ONCE RunOnce,
	_In_ ULONG Flags,
	_Outptr_opt_result_maybenull_ PVOID *Context
);

NTSYSCALLAPI
NTSTATUS
RtlRunOnceComplete (
	_Inout_ PRTL_RUN_ONCE RunOnce,
	_In_ ULONG Flags,
	_In_opt_ PVOID Context
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateEvent (
	_Out_ PHANDLE EventHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_ EVENT_TYPE EventType,
	_In_ BOOLEAN InitialState
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetEvent (
	_In_ HANDLE EventHandle,
	_Out_opt_ PLONG PreviousState
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtClearEvent (
	_In_ HANDLE EventHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtResetEvent(
	_In_ HANDLE EventHandle,
	_Out_opt_ PLONG PreviousState
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtWaitForSingleObject (
	_In_ HANDLE Handle,
	_In_ BOOLEAN Alertable,
	_In_opt_ PLARGE_INTEGER Timeout
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtWaitForMultipleObjects (
	_In_ ULONG Count,
	_In_reads_ (Count) HANDLE Handles[],
	_In_ WAIT_TYPE WaitType,
	_In_ BOOLEAN Alertable,
	_In_opt_ PLARGE_INTEGER Timeout
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetThreadExecutionState (
	_In_ EXECUTION_STATE NewFlags, // ES_* flags
	_Out_ PEXECUTION_STATE PreviousFlags
);

// Keyed Event

#define KEYEDEVENT_WAIT 0x0001
#define KEYEDEVENT_WAKE 0x0002
#define KEYEDEVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | KEYEDEVENT_WAIT | KEYEDEVENT_WAKE)

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateKeyedEvent (
	_Out_ PHANDLE KeyedEventHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_ ULONG Flags
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenKeyedEvent (
	_Out_ PHANDLE KeyedEventHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtReleaseKeyedEvent (
	_In_ HANDLE KeyedEventHandle,
	_In_ PVOID KeyValue,
	_In_ BOOLEAN Alertable,
	_In_opt_ PLARGE_INTEGER Timeout
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtWaitForKeyedEvent (
	_In_ HANDLE KeyedEventHandle,
	_In_ PVOID KeyValue,
	_In_ BOOLEAN Alertable,
	_In_opt_ PLARGE_INTEGER Timeout
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetCompressionWorkSpaceSize (
	_In_ USHORT CompressionFormatAndEngine,
	_Out_ PULONG CompressBufferWorkSpaceSize,
	_Out_ PULONG CompressFragmentWorkSpaceSize
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlCompressBuffer (
	_In_ USHORT CompressionFormatAndEngine,
	_In_reads_bytes_ (UncompressedBufferSize) PUCHAR UncompressedBuffer,
	_In_ ULONG UncompressedBufferSize,
	_Out_writes_bytes_to_ (CompressedBufferSize, *FinalCompressedSize) PUCHAR CompressedBuffer,
	_In_ ULONG CompressedBufferSize,
	_In_ ULONG UncompressedChunkSize,
	_Out_ PULONG FinalCompressedSize,
	_In_ PVOID WorkSpace
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlDecompressBuffer (
	_In_ USHORT CompressionFormat,
	_Out_writes_bytes_to_ (UncompressedBufferSize, *FinalUncompressedSize) PUCHAR UncompressedBuffer,
	_In_ ULONG UncompressedBufferSize,
	_In_reads_bytes_ (CompressedBufferSize) PUCHAR CompressedBuffer,
	_In_ ULONG CompressedBufferSize,
	_Out_ PULONG FinalUncompressedSize
);

NTSYSCALLAPI// win8+
NTSTATUS
NTAPI
RtlDecompressBufferEx (
	_In_ USHORT CompressionFormat,
	_Out_writes_bytes_to_ (UncompressedBufferSize, *FinalUncompressedSize) PUCHAR UncompressedBuffer,
	_In_ ULONG UncompressedBufferSize,
	_In_reads_bytes_ (CompressedBufferSize) PUCHAR CompressedBuffer,
	_In_ ULONG CompressedBufferSize,
	_Out_ PULONG FinalUncompressedSize,
	_In_opt_ PVOID WorkSpace
);

// win81+
NTSYSCALLAPI
NTSTATUS
NTAPI
RtlDecompressBufferEx2 (
	_In_ USHORT CompressionFormat,
	_Out_writes_bytes_to_ (UncompressedBufferSize, *FinalUncompressedSize) PUCHAR UncompressedBuffer,
	_In_ ULONG UncompressedBufferSize,
	_In_reads_bytes_ (CompressedBufferSize) PUCHAR CompressedBuffer,
	_In_ ULONG CompressedBufferSize,
	_In_ ULONG UncompressedChunkSize,
	_Out_ PULONG FinalUncompressedSize,
	_In_opt_ PVOID WorkSpace
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlDecompressFragment (
	_In_ USHORT CompressionFormat,
	_Out_writes_bytes_to_ (UncompressedFragmentSize, *FinalUncompressedSize) PUCHAR UncompressedFragment,
	_In_ ULONG UncompressedFragmentSize,
	_In_reads_bytes_ (CompressedBufferSize) PUCHAR CompressedBuffer,
	_In_ ULONG CompressedBufferSize,
	_In_range_ (< , CompressedBufferSize) ULONG FragmentOffset,
	_Out_ PULONG FinalUncompressedSize,
	_In_ PVOID WorkSpace
);

// win81+
NTSYSCALLAPI
NTSTATUS
NTAPI
RtlDecompressFragmentEx (
	_In_ USHORT CompressionFormat,
	_Out_writes_bytes_to_ (UncompressedFragmentSize, *FinalUncompressedSize) PUCHAR UncompressedFragment,
	_In_ ULONG UncompressedFragmentSize,
	_In_reads_bytes_ (CompressedBufferSize) PUCHAR CompressedBuffer,
	_In_ ULONG CompressedBufferSize,
	_In_range_ (< , CompressedBufferSize) ULONG FragmentOffset,
	_In_ ULONG UncompressedChunkSize,
	_Out_ PULONG FinalUncompressedSize,
	_In_ PVOID WorkSpace
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateKey (
	_Out_ PHANDLE KeyHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes,
	_Reserved_ ULONG TitleIndex,
	_In_opt_ PUNICODE_STRING Class,
	_In_ ULONG CreateOptions,
	_Out_opt_ PULONG Disposition
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenKey (
	_Out_ PHANDLE KeyHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes
);

// win7+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenKeyEx (
	_Out_ PHANDLE KeyHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_ ULONG OpenOptions
);

// win7+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenKeyTransactedEx (
	_Out_ PHANDLE KeyHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_ ULONG OpenOptions,
	_In_ HANDLE TransactionHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtDeleteKey (
	_In_ HANDLE KeyHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtRenameKey (
	_In_ HANDLE KeyHandle,
	_In_ PUNICODE_STRING NewName
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtDeleteValueKey (
	_In_ HANDLE KeyHandle,
	_In_ PUNICODE_STRING ValueName
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryKey (
	_In_ HANDLE KeyHandle,
	_In_ KEY_INFORMATION_CLASS KeyInformationClass,
	_Out_writes_bytes_opt_ (Length) PVOID KeyInformation,
	_In_ ULONG Length,
	_Out_ PULONG ResultLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetInformationKey (
	_In_ HANDLE KeyHandle,
	_In_ KEY_SET_INFORMATION_CLASS KeySetInformationClass,
	_In_reads_bytes_ (KeySetInformationLength) PVOID KeySetInformation,
	_In_ ULONG KeySetInformationLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryValueKey (
	_In_ HANDLE KeyHandle,
	_In_ PUNICODE_STRING ValueName,
	_In_ KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
	_Out_writes_bytes_opt_ (Length) PVOID KeyValueInformation,
	_In_ ULONG Length,
	_Out_ PULONG ResultLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetValueKey (
	_In_ HANDLE KeyHandle,
	_In_ PUNICODE_STRING ValueName,
	_In_opt_ ULONG TitleIndex,
	_In_ ULONG Type,
	_In_reads_bytes_opt_ (DataSize) PVOID Data,
	_In_ ULONG DataSize
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtEnumerateKey (
	_In_ HANDLE KeyHandle,
	_In_ ULONG Index,
	_In_ KEY_INFORMATION_CLASS KeyInformationClass,
	_Out_writes_bytes_opt_ (Length) PVOID KeyInformation,
	_In_ ULONG Length,
	_Out_ PULONG ResultLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtEnumerateValueKey (
	_In_ HANDLE KeyHandle,
	_In_ ULONG Index,
	_In_ KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
	_Out_writes_bytes_opt_ (Length) PVOID KeyValueInformation,
	_In_ ULONG Length,
	_Out_ PULONG ResultLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtFlushKey (
	_In_ HANDLE KeyHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtRestoreKey (
	_In_ HANDLE KeyHandle,
	_In_ HANDLE FileHandle,
	_In_ ULONG Flags
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSaveKey (
	_In_ HANDLE KeyHandle,
	_In_ HANDLE FileHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSaveKeyEx (
	_In_ HANDLE KeyHandle,
	_In_ HANDLE FileHandle,
	_In_ ULONG Format
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlOpenCurrentUser (
	_In_ ACCESS_MASK DesiredAccess,
	_Out_ PHANDLE CurrentUserKey
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateMutant (
	_Out_ PHANDLE MutantHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_ BOOLEAN InitialOwner
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenMutant (
	_Out_ PHANDLE MutantHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtReleaseMutant (
	_In_ HANDLE MutantHandle,
	_Out_opt_ PLONG PreviousCount
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateSection (
	_Out_ PHANDLE SectionHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_opt_ PLARGE_INTEGER MaximumSize,
	_In_ ULONG SectionPageProtection,
	_In_ ULONG AllocationAttributes,
	_In_opt_ HANDLE FileHandle
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtOpenSection (
	_Out_ PHANDLE SectionHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtMapViewOfSection (
	_In_ HANDLE SectionHandle,
	_In_ HANDLE ProcessHandle,
	_Inout_ _At_ (*BaseAddress, _Readable_bytes_ (*ViewSize) _Writable_bytes_ (*ViewSize) _Post_readable_byte_size_ (*ViewSize)) PVOID *BaseAddress,
	_In_ ULONG_PTR ZeroBits,
	_In_ ULONG_PTR CommitSize,
	_Inout_opt_ PLARGE_INTEGER SectionOffset,
	_Inout_ PULONG_PTR ViewSize,
	_In_ SECTION_INHERIT InheritDisposition,
	_In_ ULONG AllocationType,
	_In_ ULONG Win32Protect
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtUnmapViewOfSection (
	_In_ HANDLE ProcessHandle,
	_In_opt_ PVOID BaseAddress
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtExtendSection (
	_In_ HANDLE SectionHandle,
	_Inout_ PLARGE_INTEGER NewSectionSize
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQuerySection (
	_In_ HANDLE SectionHandle,
	_In_ SECTION_INFORMATION_CLASS SectionInformationClass,
	_Out_writes_bytes_ (SectionInformationLength) PVOID SectionInformation,
	_In_ ULONG_PTR SectionInformationLength,
	_Out_opt_ PULONG_PTR ReturnLength
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlCreateAcl (
	_Out_writes_bytes_ (AclLength) PACL Acl,
	_In_ ULONG AclLength,
	_In_ ULONG AclRevision
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlAddAccessAllowedAce (
	_Inout_ PACL Acl,
	_In_ ULONG AceRevision,
	_In_ ACCESS_MASK AccessMask,
	_In_ PSID Sid
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQuerySecurityObject (
	_In_ HANDLE Handle,
	_In_ SECURITY_INFORMATION SecurityInformation,
	_Out_writes_bytes_opt_ (Length) PSECURITY_DESCRIPTOR SecurityDescriptor,
	_In_ ULONG Length,
	_Out_ PULONG LengthNeeded
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlSetDaclSecurityDescriptor (
	_Inout_ PSECURITY_DESCRIPTOR SecurityDescriptor,
	_In_ BOOLEAN DaclPresent,
	_In_opt_ PACL Dacl,
	_In_ BOOLEAN DaclDefaulted
);

NTSYSCALLAPI
NTSTATUS
NTAPI
RtlGetDaclSecurityDescriptor (
	_In_ PSECURITY_DESCRIPTOR SecurityDescriptor,
	_Out_ PBOOLEAN DaclPresent,
	_Outptr_result_maybenull_ PACL * Dacl,
	_Out_ PBOOLEAN DaclDefaulted
);

// win7+
NTSYSCALLAPI
LOGICAL
NTAPI
RtlQueryPerformanceCounter (
	_Out_ PLARGE_INTEGER PerformanceCounter
);

// win7+
NTSYSCALLAPI
LOGICAL
NTAPI
RtlQueryPerformanceFrequency (
	_Out_ PLARGE_INTEGER PerformanceFrequency
);

// win8+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtCreateWnfStateName (
	_Out_ PWNF_STATE_NAME StateName,
	_In_ WNF_STATE_NAME_LIFETIME NameLifetime,
	_In_ WNF_DATA_SCOPE DataScope,
	_In_ BOOLEAN PersistData,
	_In_opt_ PCWNF_TYPE_ID TypeId,
	_In_ ULONG MaximumStateSize,
	_In_ PSECURITY_DESCRIPTOR SecurityDescriptor
);

// win8+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtDeleteWnfStateName (
	_In_ PCWNF_STATE_NAME StateName
);

// win8+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtUpdateWnfStateData (
	_In_ PCWNF_STATE_NAME StateName,
	_In_reads_bytes_opt_ (Length) const PVOID Buffer,
	_In_opt_ ULONG Length,
	_In_opt_ PCWNF_TYPE_ID TypeId,
	_In_opt_ const PVOID ExplicitScope,
	_In_ WNF_CHANGE_STAMP MatchingChangeStamp,
	_In_ LOGICAL CheckStamp
);

// win8+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtDeleteWnfStateData (
	_In_ PCWNF_STATE_NAME StateName,
	_In_opt_ const PVOID ExplicitScope
);

// win8+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryWnfStateData (
	_In_ PCWNF_STATE_NAME StateName,
	_In_opt_ PCWNF_TYPE_ID TypeId,
	_In_opt_ const PVOID ExplicitScope,
	_Out_ PWNF_CHANGE_STAMP ChangeStamp,
	_Out_writes_bytes_to_opt_ (*BufferSize, *BufferSize) PVOID Buffer,
	_Inout_ PULONG BufferSize
);

// win8+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryWnfStateNameInformation (
	_In_ PCWNF_STATE_NAME StateName,
	_In_ WNF_STATE_NAME_INFORMATION NameInfoClass,
	_In_opt_ const PVOID ExplicitScope,
	_Out_writes_bytes_ (InfoBufferSize) PVOID InfoBuffer,
	_In_ ULONG InfoBufferSize
);

// win8+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtSubscribeWnfStateChange (
	_In_ PCWNF_STATE_NAME StateName,
	_In_opt_ WNF_CHANGE_STAMP ChangeStamp,
	_In_ ULONG EventMask,
	_Out_opt_ PULONG64 SubscriptionId
);

// win8+
NTSYSCALLAPI
NTSTATUS
NTAPI
NtUnsubscribeWnfStateChange (
	_In_ PCWNF_STATE_NAME StateName
);

// extern c end
EXTERN_C_END
