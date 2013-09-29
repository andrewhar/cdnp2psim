//stats related definition
//
typedef unsigned int TUpTimeStatsPeer;
typedef unsigned int TDownTimeStatsPeer;
typedef unsigned int TRequestStatsPeer;

typedef struct statsPeer TStatsPeer;

TStatsPeer *initStatsPeer();
TRequestStatsPeer getRequestStatsPeer(TStatsPeer *stats);
TUpTimeStatsPeer getUpTimeStatsPeer(TStatsPeer *stats);
TDownTimeStatsPeer getDownTimeStatsPeer(TStatsPeer *stats);

void setRequestStatPeer(TStatsPeer *stats, TRequestStatsPeer request);
void setUpTimeStatsPeer(TStatsPeer *stats, TUpTimeStatsPeer upTime);
void setDownTimeStatsPeer(TStatsPeer *stats, TDownTimeStatsPeer downTime);

void addRequestStatsPeer(TStatsPeer *stats, TRequestStatsPeer amount);
void addUpTimeStatsPeer(TStatsPeer *stats, TUpTimeStatsPeer amount);
void addDownTimeStatsPeer(TStatsPeer *stats, TDownTimeStatsPeer amount);

// Peer related definition
//
//
typedef struct peer TPeer;
typedef enum{DOWN_PEER=1, UP_PEER=2, STALL_PEER=4} TStatusPeer;

typedef TStatsPeer* (* TGetOnStatsPeer)(TPeer *peer);
typedef unsigned int (* TGetIdPeer)(TPeer *peer);
typedef short(* TGetStatusPeer)(TPeer *peer);
typedef void *(* TGetDynamicJoinPeer)(TPeer *peer);
typedef void *(* TGetDynamicLeavePeer)(TPeer *peer);
typedef void *(* TGetDynamicRequestPeer)(TPeer *peer);
typedef unsigned int (* TGetRequestTimePeer)(TPeer* peer);
typedef unsigned int (* TGetReplicateTimePeer)(TPeer* peer);
typedef unsigned int (* TGetUpSessionDurationPeer)(TPeer* peer);
typedef unsigned int (* TGetDownSessionDurationPeer)(TPeer* peer);
typedef void *(* TGetCachePeer)(TPeer* peer);
typedef void *(* TGetReplicatePeer)(TPeer* peer);
typedef void *(* TGetDataSourcePeer)(TPeer* peer);
typedef void (* TSetStatusPeer)(TPeer *peer, short status);
typedef void (* TSetDynamicJoinPeer)(TPeer *peer, void *dynamicJoin);
typedef void (* TSetDynamicLeavePeer)(TPeer *peer, void *dynamicLeave);
typedef void (* TSetDynamicRequestPeer)(TPeer *peer, void *dynamicRequest);
typedef void (* TSetCachePeer)(TPeer* peer, void *cache);
typedef void (* TSetDataSourcePeer)(TPeer *peer, void *dataSource);
typedef short (* TIsUpPeer)(TPeer* peer);
typedef short (* TIsDownPeer)(TPeer* peer);
typedef void (* TSetupJoiningPeer)(TPeer *peer);
typedef void *(* TGetTopologyManagerPeer)(TPeer *peer);
typedef void (* TSetTopologyManagerPeer)(TPeer *peer, void* tm);
typedef short (* THasCachedPeer)(TPeer *peer, void* object);
typedef void (* TSetTierPeer)(TPeer *peer, short tier);
typedef short (*TGetTierPeer)(TPeer *peer);
typedef void (*TUpdateCachePeer)(TPeer *peer, void *vObject, void *vSystemData);
typedef short (*TInsertCachePeer)(TPeer *peer, void *vObject, void *vSystemData);
typedef void *(*TGetEvictedCachePeer)(TPeer *peer);

typedef void *(*TGetProfilePeer)(TPeer *peer);
typedef float (*TRunProfilePolicyPeer)(TPeer *peer, void *profile);
typedef void (*TSetProfilePolicyPeer)(TPeer *peer, void* profilePolicy);

typedef void (*TUpdateRequestsMapQueryPeer)(TPeer *peer, unsigned int idSource, short hops);
typedef void (*TUpdateHitsMapQueryPeer)(TPeer *peer, unsigned int idSource, short hops);
typedef void (*TShowMapQueryPeer)(TPeer *peer);

TPeer* createPeer(unsigned int id, short tier, void *pickDataOnSessionDynamic, void *pickDataOffSessionDynamic, void *pickDataRequest, void *dataSource, void *replicate, void *cache, void *topologyManager );

struct peer {
	void *data;

	//public methods
		TGetOnStatsPeer getOnStats;
		TGetIdPeer getId;
		TGetStatusPeer getStatus;
		TGetDynamicJoinPeer getDynamicJoin;
		TGetDynamicLeavePeer getDynamicLeave;
		TGetDynamicRequestPeer getDynamicRequest;
		TGetRequestTimePeer getRequestTime;
		TGetReplicateTimePeer getReplicateTime;
		TGetUpSessionDurationPeer getUpSessionDuration;
		TGetDownSessionDurationPeer getDownSessionDuration;
		TGetCachePeer getCache;
		TGetReplicatePeer getReplicate;
		TGetDataSourcePeer getDataSource;
		TGetTopologyManagerPeer getTopologyManager;
		TSetTopologyManagerPeer setTopologyManager;
		TSetStatusPeer setStatus;
		TSetDynamicJoinPeer setDynamicJoin;
		TSetDynamicLeavePeer setDynamicLeave;
		TSetDynamicRequestPeer setDynamicRequest;
		TSetCachePeer setCache;
		TSetDataSourcePeer setDataSource;
		TSetupJoiningPeer setupJoining;
		TIsUpPeer isUp;
		TIsDownPeer isDown;
		THasCachedPeer hasCached;
		TSetTierPeer setTier;
		TGetTierPeer getTier;
		TInsertCachePeer insertCache;
		TUpdateCachePeer updateCache;
		TUpdateCachePeer updateCacheAsServer;
		TGetEvictedCachePeer getEvictedCache;
		TGetProfilePeer getProfile;
		TRunProfilePolicyPeer runProfilePolicy;
		TSetProfilePolicyPeer setProfilePolicy;

		TUpdateHitsMapQueryPeer updateHitsMapQuery;
		TUpdateRequestsMapQueryPeer updateRequestsMapQuery;
		TShowMapQueryPeer showMapQuery;
};

void *createAnderbergContentProfilePeer(void *entry);
void *createJaccardContentProfilePeer(void *entry);


void *createRandomSessionLasting(void *entry);
void *createPlaylistSessionLasting(void *entry);
void *createPartialPlaylistSessionLasting(void *entry);