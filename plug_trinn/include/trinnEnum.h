#ifndef TRINNENUM_H
#define TRINNENUM_H

#include <QtCore/QObject>

namespace Trinn {
    Q_NAMESPACE
    enum class TransactionConfirm {
        No_required = 0,
        Waiting,
        Received,
    };

    enum class TransactionType { // 3 bit
        None = 0,
        Transfer,
        Income,
        Magnet,
        Spend,
        Plan,
    };

    enum class TransactionRegular {
        Once = 0,
        Daily,
        Weekly,
        Monthly,
        Yearly,
        Periodical,
        OnRequest,
    };

    enum class LotType { // 4 bit
        None = 0,
        Card,
        Currency,
        Merchant,
        Category,
        Project,
        Transaction,
    };

    enum class SubjectType { // 2 bit
        User = 0,
        Organization,
        Group,
    };

    // http://statisticstimes.com/article/performance-of-currencies-2018.php
    enum class Currency {
        // Africa
        South_African_Rand = 0xA00, // ZAR
        Kenyan_Shilling,  // KES
        Egyptian_Pound,   // EGP
        Moroccan_Dirham,  // MAD
        CFA_Franc,        // XOF
        Nigerian_Naira ,  // NGN
        Tunisian_Dinar,   // TND
        Ugandan_Shilling, // UGX
        Central_African,  // XAF
        Libyan_Dinar,     // LYD

        // Asia
        Indian_Rupee = 0xB00,  // INR
        Singapore_Dollar,      // SGD
        Malaysian_Ringgit,     // MYR
        Japanese_Yen,          // JPY
        Chinese_Yuan_Renminbi, // CNY
        Thai_Baht,             // THB
        Emirati_Dirham,        // AED
        Hong_Kong_Dollar,      // HKD
        Philippine_Piso,       // PHP
        Indonesian_Rupiah,     // IDR
        Saudi_Arabian_Riyal,   // SAR
        South_Korean_Won,      // KRW
        Iraqi_Dinar,           // IQD
        Kuwaiti_Dinar,         // KWD
        Russian_Ruble,         // RUB
        Pakistani_Rupee,       // PKR
        Israeli_Shekel,        // ILS
        Qatari_Riyal,          // QAR
        Omani_Rial,            // OMR
        Taiwan_New_Dollar,     // TWD
        Vietnamese_Dong,       // VND
        Jordanian_Dinar,       // JOD
        Bahraini_Dinar,        // BHD
        Sri_Lankan_Rupee,      // LKR
        Bangladeshi_Taka,      // BDT
        Uzbekistani_Som,       // UZS
        Algerian_Dinar,        // DZD
        Iranian_Rial,          // IRR
        Syrian_Pound,          // SYP

        // Europe
        Euro = 0xC00,      // EUR
        British_Pound,     // GBP
        Swiss_Franc,       // CHF
        Hungarian_Forint,  // HUF
        Swedish_Krona,     // SEK
        Turkish_Lira,      // TRY
        Norwegian_Krone,   // NOK
        Danish_Krone,      // DKK
        Polish_Zloty,      // PLN
        Czech_Koruna,      // CZK
        Ukrainian_Hryvnia, // UAH
        Romanian_Leu,      // RON
        Georgian_Lari,     // GEL
        Belarusian_Ruble,  // BYN
        Croatian_Kuna,     // HRK,
        Bulgarian_Lev,     // BGN
        Icelandic_Krona,   // ISK

        // North America
        US_Dollar = 0xD00, // USD
        Canadian_Dollar,   // CAD
        Mexican_Peso,      // MXN
        Dominican_Peso,    // DOP,
        Costa_Rican_Colon, // CRC,

        // Oceania
        Australian_Dollar = 0xE00, // AUD
        New_Zealand_Dollar,        // NZD
        Fijian_Dollar,             // FJD

        // South America
        Brazilian_Real = 0xF00, // BRL
        Colombian_Peso,         // COP
        Chilean_Peso,           // CLP
        Argentine_Peso,         // ARS
        Peruvian_Sol,           // PEN
        Venezuelan_Bolivar,     // VES
    };

    typedef TransactionType    Ttype;
    typedef TransactionConfirm Tconfirm;
    typedef TransactionRegular Tregular;
}

#endif // TRINNENUM_H
