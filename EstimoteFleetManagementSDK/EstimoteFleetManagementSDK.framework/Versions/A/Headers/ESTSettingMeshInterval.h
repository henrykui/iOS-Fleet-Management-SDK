//  FleetManagementSDK
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingMeshIntervalErrorDomain @"ESTSettingMeshIntervalErrorDomain"

/**
 *  Describes Mesh Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingMeshIntervalError)
{
    /**
     *  Provided value is too small - should be equal or bigger than 100ms.
     */
    ESTSettingMeshIntervalErrorTooSmall = 1,
    
    /**
     *  Provided value is too big - should be less or equal 10000 ms.
     */
    ESTSettingMeshIntervalErrorTooBig = 2
};

@class ESTSettingMeshInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Interval operation for Mesh packet.
 *
 *  @param intervalSetting Interval setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingMeshIntervalCompletionBlock)(ESTSettingMeshInterval * _Nullable intervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingMeshInterval represents Mesh Interval value.
 */
@interface ESTSettingMeshInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingMeshInterval validationErrorForValue:]
 *
 *  @param interval Mesh Interval value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(unsigned short)interval;

/**
 *  Returns current value of Mesh Interval setting.
 *
 *  @return Mesh Interval value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized Mesh Interval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingMeshIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Mesh Interval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param interval Interval value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(unsigned short)interval completion:(ESTSettingMeshIntervalCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param interval Interval value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(unsigned short)interval;

@end

NS_ASSUME_NONNULL_END
