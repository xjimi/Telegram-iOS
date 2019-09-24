#import <Foundation/Foundation.h>

@interface DeviceSpecificEncryptionParameters : NSObject

@property (nonatomic, strong) NSData * _Nonnull key;
@property (nonatomic, strong) NSData * _Nonnull salt;

@end

@interface BuildConfig : NSObject

- (instancetype _Nonnull)initWithBaseAppBundleId:(NSString * _Nonnull)baseAppBundleId;

@property (nonatomic, strong, readonly) NSString * _Nullable hockeyAppId;
@property (nonatomic, readonly) int32_t apiId;
@property (nonatomic, strong, readonly) NSString * _Nonnull apiHash;
@property (nonatomic, readonly) bool isInternalBuild;
@property (nonatomic, readonly) bool isAppStoreBuild;
@property (nonatomic, readonly) int64_t appStoreId;
@property (nonatomic, strong, readonly) NSString * _Nonnull appSpecificUrlScheme;

+ (DeviceSpecificEncryptionParameters * _Nonnull)deviceSpecificEncryptionParameters:(NSString * _Nonnull)rootPath baseAppBundleId:(NSString * _Nonnull)baseAppBundleId;
- (NSData * _Nullable)bundleDataWithAppToken:(NSData * _Nullable)appToken;

+ (void)getHardwareEncryptionAvailableWithBaseAppBundleId:(NSString * _Nonnull)baseAppBundleId completion:(void (^)(NSData * _Nullable))completion;
+ (void)encryptApplicationSecret:(NSData * _Nonnull)secret baseAppBundleId:(NSString * _Nonnull)baseAppBundleId completion:(void (^)(NSData * _Nullable, NSData * _Nullable))completion;
+ (void)decryptApplicationSecret:(NSData * _Nonnull)secret publicKey:(NSData * _Nonnull)publicKey baseAppBundleId:(NSString * _Nonnull)baseAppBundleId completion:(void (^)(NSData * _Nullable))completion;

@end
