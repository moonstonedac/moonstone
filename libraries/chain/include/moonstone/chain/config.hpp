/*
 * Copyright (c) 2015 Cryptonomex, Inc., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once

#define MOONSTONE_SYMBOL "XMS"
#define MOONSTONE_ADDRESS_PREFIX "XMS"

#define MOONSTONE_MIN_ACCOUNT_NAME_LENGTH 1
#define MOONSTONE_MAX_ACCOUNT_NAME_LENGTH 63

#define MOONSTONE_MIN_ASSET_SYMBOL_LENGTH 3
#define MOONSTONE_MAX_ASSET_SYMBOL_LENGTH 16

#define MOONSTONE_MAX_SHARE_SUPPLY int64_t(1000000000000000ll)
#define MOONSTONE_MAX_PAY_RATE 10000 /* 100% */
#define MOONSTONE_MAX_SIG_CHECK_DEPTH 2
/**
 * Don't allow the committee_members to publish a limit that would
 * make the network unable to operate.
 */
#define MOONSTONE_MIN_TRANSACTION_SIZE_LIMIT 1024
#define MOONSTONE_MIN_BLOCK_INTERVAL   1 /* seconds */
#define MOONSTONE_MAX_BLOCK_INTERVAL  30 /* seconds */

#define MOONSTONE_DEFAULT_BLOCK_INTERVAL  5 /* seconds */
#define MOONSTONE_DEFAULT_MAX_TRANSACTION_SIZE 2048
#define MOONSTONE_DEFAULT_MAX_BLOCK_SIZE  (MOONSTONE_DEFAULT_MAX_TRANSACTION_SIZE*MOONSTONE_DEFAULT_BLOCK_INTERVAL*200000)
#define MOONSTONE_DEFAULT_MAX_TIME_UNTIL_EXPIRATION (60*60*24) // seconds,  aka: 1 day
#define MOONSTONE_DEFAULT_MAINTENANCE_INTERVAL  (60*60*24) // seconds, aka: 1 day
#define MOONSTONE_DEFAULT_MAINTENANCE_SKIP_SLOTS 3  // number of slots to skip for maintenance interval

#define MOONSTONE_MIN_UNDO_HISTORY 10
#define MOONSTONE_MAX_UNDO_HISTORY 10000

#define MOONSTONE_MIN_BLOCK_SIZE_LIMIT (MOONSTONE_MIN_TRANSACTION_SIZE_LIMIT*5) // 5 transactions per block
#define MOONSTONE_MIN_TRANSACTION_EXPIRATION_LIMIT (MOONSTONE_MAX_BLOCK_INTERVAL * 5) // 5 transactions per block
#define MOONSTONE_BLOCKCHAIN_PRECISION                           uint64_t( 100000 )

#define MOONSTONE_BLOCKCHAIN_PRECISION_DIGITS                    5
#define MOONSTONE_DEFAULT_TRANSFER_FEE                           (1*MOONSTONE_BLOCKCHAIN_PRECISION)
#define MOONSTONE_MAX_INSTANCE_ID                                (uint64_t(-1)>>16)
/** percentage fields are fixed point with a denominator of 10,000 */
#define MOONSTONE_100_PERCENT                                    10000
#define MOONSTONE_1_PERCENT                                      (MOONSTONE_100_PERCENT/100)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define MOONSTONE_MAX_MARKET_FEE_PERCENT                         MOONSTONE_100_PERCENT
#define MOONSTONE_DEFAULT_FORCE_SETTLEMENT_DELAY                 (60*60*24) ///< 1 day
#define MOONSTONE_DEFAULT_FORCE_SETTLEMENT_OFFSET                0 ///< 1%
#define MOONSTONE_DEFAULT_FORCE_SETTLEMENT_MAX_VOLUME            (20* MOONSTONE_1_PERCENT) ///< 20%
#define MOONSTONE_DEFAULT_PRICE_FEED_LIFETIME                    (60*60*24) ///< 1 day
#define MOONSTONE_MAX_FEED_PRODUCERS                             200
#define MOONSTONE_DEFAULT_MAX_AUTHORITY_MEMBERSHIP               10
#define MOONSTONE_DEFAULT_MAX_ASSET_WHITELIST_AUTHORITIES        10
#define MOONSTONE_DEFAULT_MAX_ASSET_FEED_PUBLISHERS              10

/**
 *  These ratios are fixed point numbers with a denominator of MOONSTONE_COLLATERAL_RATIO_DENOM, the
 *  minimum maitenance collateral is therefore 1.001x and the default
 *  maintenance ratio is 1.75x
 */
///@{
#define MOONSTONE_COLLATERAL_RATIO_DENOM                 1000
#define MOONSTONE_MIN_COLLATERAL_RATIO                   1001  ///< lower than this could result in divide by 0
#define MOONSTONE_MAX_COLLATERAL_RATIO                   32000 ///< higher than this is unnecessary and may exceed int16 storage
#define MOONSTONE_DEFAULT_MAINTENANCE_COLLATERAL_RATIO   1750 ///< Call when collateral only pays off 175% the debt
#define MOONSTONE_DEFAULT_MAX_SHORT_SQUEEZE_RATIO        1500 ///< Stop calling when collateral only pays off 150% of the debt
///@}
#define MOONSTONE_DEFAULT_MARGIN_PERIOD_SEC              (30*60*60*24)

#define MOONSTONE_DEFAULT_MIN_WITNESS_COUNT                    (11)
#define MOONSTONE_DEFAULT_MIN_COMMITTEE_MEMBER_COUNT           (11)
#define MOONSTONE_DEFAULT_MAX_WITNESSES                        (1001) // SHOULD BE ODD
#define MOONSTONE_DEFAULT_MAX_COMMITTEE                        (1001) // SHOULD BE ODD
#define MOONSTONE_DEFAULT_MAX_PROPOSAL_LIFETIME_SEC            (60*60*24*7*4) // Four weeks
#define MOONSTONE_DEFAULT_COMMITTEE_PROPOSAL_REVIEW_PERIOD_SEC (60*60*24*7*2) // Two weeks
#define MOONSTONE_DEFAULT_NETWORK_PERCENT_OF_FEE               (20*MOONSTONE_1_PERCENT)
#define MOONSTONE_DEFAULT_LIFETIME_REFERRER_PERCENT_OF_FEE     (30*MOONSTONE_1_PERCENT)
#define MOONSTONE_DEFAULT_MAX_BULK_DISCOUNT_PERCENT            (50*MOONSTONE_1_PERCENT)
#define MOONSTONE_DEFAULT_BULK_DISCOUNT_THRESHOLD_MIN          ( MOONSTONE_BLOCKCHAIN_PRECISION*int64_t(1000) )
#define MOONSTONE_DEFAULT_BULK_DISCOUNT_THRESHOLD_MAX          ( MOONSTONE_DEFAULT_BULK_DISCOUNT_THRESHOLD_MIN*int64_t(100) )
#define MOONSTONE_DEFAULT_CASHBACK_VESTING_PERIOD_SEC          (60*60*24*365) ///< 1 year
#define MOONSTONE_DEFAULT_CASHBACK_VESTING_THRESHOLD           (MOONSTONE_BLOCKCHAIN_PRECISION*int64_t(100))
#define MOONSTONE_DEFAULT_BURN_PERCENT_OF_FEE                  (20*MOONSTONE_1_PERCENT)
#define MOONSTONE_WITNESS_PAY_PERCENT_PRECISION                (1000000000)
#define MOONSTONE_DEFAULT_MAX_ASSERT_OPCODE                    1
#define MOONSTONE_DEFAULT_FEE_LIQUIDATION_THRESHOLD            MOONSTONE_BLOCKCHAIN_PRECISION * 100;
#define MOONSTONE_DEFAULT_ACCOUNTS_PER_FEE_SCALE               1000
#define MOONSTONE_DEFAULT_ACCOUNT_FEE_SCALE_BITSHIFTS          4
#define MOONSTONE_DEFAULT_MAX_BUYBACK_MARKETS                  4

#define MOONSTONE_MAX_WORKER_NAME_LENGTH                       63

#define MOONSTONE_MAX_URL_LENGTH                               127

// counter initialization values used to derive near and far future seeds for shuffling witnesses
// we use the fractional bits of sqrt(2) in hex
#define MOONSTONE_NEAR_SCHEDULE_CTR_IV                    ( (uint64_t( 0x6a09 ) << 0x30)    \
                                                         | (uint64_t( 0xe667 ) << 0x20)    \
                                                         | (uint64_t( 0xf3bc ) << 0x10)    \
                                                         | (uint64_t( 0xc908 )        ) )

// and the fractional bits of sqrt(3) in hex
#define MOONSTONE_FAR_SCHEDULE_CTR_IV                     ( (uint64_t( 0xbb67 ) << 0x30)    \
                                                         | (uint64_t( 0xae85 ) << 0x20)    \
                                                         | (uint64_t( 0x84ca ) << 0x10)    \
                                                         | (uint64_t( 0xa73b )        ) )

/**
 * every second, the fraction of burned core asset which cycles is
 * MOONSTONE_CORE_ASSET_CYCLE_RATE / (1 << MOONSTONE_CORE_ASSET_CYCLE_RATE_BITS)
 */
#define MOONSTONE_CORE_ASSET_CYCLE_RATE                        17
#define MOONSTONE_CORE_ASSET_CYCLE_RATE_BITS                   32

#define MOONSTONE_DEFAULT_WITNESS_PAY_PER_BLOCK            (MOONSTONE_BLOCKCHAIN_PRECISION * int64_t( 10) )
#define MOONSTONE_DEFAULT_WITNESS_PAY_VESTING_SECONDS      (60*60*24)
#define MOONSTONE_DEFAULT_WORKER_BUDGET_PER_DAY            (MOONSTONE_BLOCKCHAIN_PRECISION * int64_t(500) * 1000 )

#define MOONSTONE_DEFAULT_MINIMUM_FEEDS                       7

#define MOONSTONE_MAX_INTEREST_APR                            uint16_t( 10000 )

#define MOONSTONE_RECENTLY_MISSED_COUNT_INCREMENT             4
#define MOONSTONE_RECENTLY_MISSED_COUNT_DECREMENT             3

#define MOONSTONE_CURRENT_DB_VERSION                          "XMS1.0"

#define MOONSTONE_IRREVERSIBLE_THRESHOLD                      (70 * MOONSTONE_1_PERCENT)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current committee members, two-week review period
#define MOONSTONE_COMMITTEE_ACCOUNT (moonstone::chain::account_id_type(0))
/// Represents the current witnesses
#define MOONSTONE_WITNESS_ACCOUNT (moonstone::chain::account_id_type(1))
/// Represents the current committee members
#define MOONSTONE_RELAXED_COMMITTEE_ACCOUNT (moonstone::chain::account_id_type(2))
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define MOONSTONE_NULL_ACCOUNT (moonstone::chain::account_id_type(3))
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define MOONSTONE_TEMP_ACCOUNT (moonstone::chain::account_id_type(4))
/// Represents the canonical account for specifying you will vote directly (as opposed to a proxy)
#define MOONSTONE_PROXY_TO_SELF_ACCOUNT (moonstone::chain::account_id_type(5))
/// Sentinel value used in the scheduler.
#define MOONSTONE_NULL_WITNESS (moonstone::chain::witness_id_type(0))
///@}

#define MOONSTONE_FBA_STEALTH_DESIGNATED_ASSET (asset_id_type(743))
