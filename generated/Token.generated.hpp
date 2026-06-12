enum class TokenType
{
	Keyword_DefFunc,
	Keyword_DefProc,
	Keyword_Return,
	Keyword_Switch,
	Keyword_Case,
	Keyword_If,
	Keyword_Else,
	Keyword_Loop,
	Keyword_Break,
	Typename_Unsigned8,
	Typename_Unsigned16,
	Typename_Unsigned32,
	Typename_Unsigned64,
	Typename_Unsigned128,
	Typename_Signed8,
	Typename_Signed16,
	Typename_Signed32,
	Typename_Signed64,
	Typename_Signed128,
	Typename_Boolean,
	Typename_Bitfield8,
	Typename_Bitfield16,
	Typename_Bitfield32,
	Typename_Bitfield64,
	Typename_Bitfield128,
	Typename_FloatHalf,
	Typename_FloatSingle,
	Typename_FloatDouble,
	Typename_UnsignedSize,
	Typename_SignedSize,
	Punctuation_LParen,
	Punctuation_RParen,
	Punctuation_LBracket,
	Punctuation_RBracket,
	Punctuation_LBrace,
	Punctuation_RBrace,
	Punctuation_Bang,
	Punctuation_At,
	Punctuation_Pound,
	Punctuation_Dollar,
	Punctuation_Percent,
	Punctuation_Caret,
	Punctuation_Amp,
	Punctuation_Star,
	Punctuation_Plus,
	Punctuation_Minus,
	Punctuation_Equal,
	Punctuation_ForwardSlash,
	Punctuation_BackSlash,
	Punctuation_Pipe,
	Punctuation_Colon,
	Punctuation_Semicolon,
	Punctuation_Comma,
	Punctuation_Period,
	Punctuation_Question,
	Punctuation_Tilde,
	Punctuation_SingleQuote,
	Punctuation_DoubleQuote,
	Punctuation_Less,
	Punctuation_Greater,
	Punctuation_DoublePipe,
	Punctuation_DoubleAmp,
	Punctuation_DoubleEqual,
	Punctuation_DoublePlus,
	Punctuation_DoubleMinus,
	Punctuation_DoubleQuestion,
	Punctuation_DoubleGreater,
	Punctuation_DoubleLess,
	Punctuation_DoubleColon,
	Punctuation_BangEqual,
	Punctuation_PipeEqual,
	Punctuation_AmpEqual,
	Punctuation_CaretEqual,
	Punctuation_PlusEqual,
	Punctuation_MinusEqual,
	Punctuation_StarEqual,
	Punctuation_SlashEqual,
	Punctuation_PercentEqual,
	Punctuation_DoubleGreaterEqual,
	Punctuation_DoubleLessEqual,
	Punctuation_LessEqual,
	Punctuation_GreaterEqual,
	Punctuation_RArrow,
	Punctuation_LArrow,
	Punctuation_FatArrow,
	Punctuation_DoublePeriod,
	Punctuation_DoublePeriodEqual,
	Punctuation_DoubleQuestionEqual,
};
static inline constexpr std::string_view DefFuncString = R"_LexStr_(fn)_LexStr_";
static inline constexpr std::string_view DefProcString = R"_LexStr_(proc)_LexStr_";
static inline constexpr std::string_view ReturnString = R"_LexStr_(return)_LexStr_";
static inline constexpr std::string_view SwitchString = R"_LexStr_(switch)_LexStr_";
static inline constexpr std::string_view CaseString = R"_LexStr_(case)_LexStr_";
static inline constexpr std::string_view IfString = R"_LexStr_(if)_LexStr_";
static inline constexpr std::string_view ElseString = R"_LexStr_(else)_LexStr_";
static inline constexpr std::string_view LoopString = R"_LexStr_(loop)_LexStr_";
static inline constexpr std::string_view BreakString = R"_LexStr_(break)_LexStr_";
static inline constexpr std::string_view Unsigned8String = R"_LexStr_(u8)_LexStr_";
static inline constexpr std::string_view Unsigned16String = R"_LexStr_(u16)_LexStr_";
static inline constexpr std::string_view Unsigned32String = R"_LexStr_(u32)_LexStr_";
static inline constexpr std::string_view Unsigned64String = R"_LexStr_(u64)_LexStr_";
static inline constexpr std::string_view Unsigned128String = R"_LexStr_(u128)_LexStr_";
static inline constexpr std::string_view Signed8String = R"_LexStr_(i8)_LexStr_";
static inline constexpr std::string_view Signed16String = R"_LexStr_(i16)_LexStr_";
static inline constexpr std::string_view Signed32String = R"_LexStr_(i32)_LexStr_";
static inline constexpr std::string_view Signed64String = R"_LexStr_(i64)_LexStr_";
static inline constexpr std::string_view Signed128String = R"_LexStr_(i128)_LexStr_";
static inline constexpr std::string_view BooleanString = R"_LexStr_(bool)_LexStr_";
static inline constexpr std::string_view Bitfield8String = R"_LexStr_(b8)_LexStr_";
static inline constexpr std::string_view Bitfield16String = R"_LexStr_(b16)_LexStr_";
static inline constexpr std::string_view Bitfield32String = R"_LexStr_(b32)_LexStr_";
static inline constexpr std::string_view Bitfield64String = R"_LexStr_(b64)_LexStr_";
static inline constexpr std::string_view Bitfield128String = R"_LexStr_(b128)_LexStr_";
static inline constexpr std::string_view FloatHalfString = R"_LexStr_(f16)_LexStr_";
static inline constexpr std::string_view FloatSingleString = R"_LexStr_(f32)_LexStr_";
static inline constexpr std::string_view FloatDoubleString = R"_LexStr_(f64)_LexStr_";
static inline constexpr std::string_view UnsignedSizeString = R"_LexStr_(usize)_LexStr_";
static inline constexpr std::string_view SignedSizeString = R"_LexStr_(isize)_LexStr_";
static inline constexpr std::string_view LParenString = R"_LexStr_(()_LexStr_";
static inline constexpr std::string_view RParenString = R"_LexStr_())_LexStr_";
static inline constexpr std::string_view LBracketString = R"_LexStr_([)_LexStr_";
static inline constexpr std::string_view RBracketString = R"_LexStr_(])_LexStr_";
static inline constexpr std::string_view LBraceString = R"_LexStr_({)_LexStr_";
static inline constexpr std::string_view RBraceString = R"_LexStr_(})_LexStr_";
static inline constexpr std::string_view BangString = R"_LexStr_(!)_LexStr_";
static inline constexpr std::string_view AtString = R"_LexStr_(@)_LexStr_";
static inline constexpr std::string_view PoundString = R"_LexStr_(#)_LexStr_";
static inline constexpr std::string_view DollarString = R"_LexStr_($)_LexStr_";
static inline constexpr std::string_view PercentString = R"_LexStr_(%)_LexStr_";
static inline constexpr std::string_view CaretString = R"_LexStr_(^)_LexStr_";
static inline constexpr std::string_view AmpString = R"_LexStr_(&)_LexStr_";
static inline constexpr std::string_view StarString = R"_LexStr_(*)_LexStr_";
static inline constexpr std::string_view PlusString = R"_LexStr_(+)_LexStr_";
static inline constexpr std::string_view MinusString = R"_LexStr_(-)_LexStr_";
static inline constexpr std::string_view EqualString = R"_LexStr_(=)_LexStr_";
static inline constexpr std::string_view ForwardSlashString = R"_LexStr_(/)_LexStr_";
static inline constexpr std::string_view BackSlashString = R"_LexStr_(\)_LexStr_";
static inline constexpr std::string_view PipeString = R"_LexStr_(|)_LexStr_";
static inline constexpr std::string_view ColonString = R"_LexStr_()_LexStr_";
static inline constexpr std::string_view SemicolonString = R"_LexStr_(;)_LexStr_";
static inline constexpr std::string_view CommaString = R"_LexStr_(,)_LexStr_";
static inline constexpr std::string_view PeriodString = R"_LexStr_(.)_LexStr_";
static inline constexpr std::string_view QuestionString = R"_LexStr_(?)_LexStr_";
static inline constexpr std::string_view TildeString = R"_LexStr_(~)_LexStr_";
static inline constexpr std::string_view SingleQuoteString = R"_LexStr_(')_LexStr_";
static inline constexpr std::string_view DoubleQuoteString = R"_LexStr_(")_LexStr_";
static inline constexpr std::string_view LessString = R"_LexStr_(<)_LexStr_";
static inline constexpr std::string_view GreaterString = R"_LexStr_(>)_LexStr_";
static inline constexpr std::string_view DoublePipeString = R"_LexStr_(||)_LexStr_";
static inline constexpr std::string_view DoubleAmpString = R"_LexStr_(&&)_LexStr_";
static inline constexpr std::string_view DoubleEqualString = R"_LexStr_(==)_LexStr_";
static inline constexpr std::string_view DoublePlusString = R"_LexStr_(++)_LexStr_";
static inline constexpr std::string_view DoubleMinusString = R"_LexStr_(--)_LexStr_";
static inline constexpr std::string_view DoubleQuestionString = R"_LexStr_(??)_LexStr_";
static inline constexpr std::string_view DoubleGreaterString = R"_LexStr_(>>)_LexStr_";
static inline constexpr std::string_view DoubleLessString = R"_LexStr_(<<)_LexStr_";
static inline constexpr std::string_view DoubleColonString = R"_LexStr_(:)_LexStr_";
static inline constexpr std::string_view BangEqualString = R"_LexStr_(!=)_LexStr_";
static inline constexpr std::string_view PipeEqualString = R"_LexStr_(|=)_LexStr_";
static inline constexpr std::string_view AmpEqualString = R"_LexStr_(&=)_LexStr_";
static inline constexpr std::string_view CaretEqualString = R"_LexStr_(^=)_LexStr_";
static inline constexpr std::string_view PlusEqualString = R"_LexStr_(+=)_LexStr_";
static inline constexpr std::string_view MinusEqualString = R"_LexStr_(-=)_LexStr_";
static inline constexpr std::string_view StarEqualString = R"_LexStr_(*=)_LexStr_";
static inline constexpr std::string_view SlashEqualString = R"_LexStr_(/=)_LexStr_";
static inline constexpr std::string_view PercentEqualString = R"_LexStr_(%=)_LexStr_";
static inline constexpr std::string_view DoubleGreaterEqualString = R"_LexStr_(>>=)_LexStr_";
static inline constexpr std::string_view DoubleLessEqualString = R"_LexStr_(<<=)_LexStr_";
static inline constexpr std::string_view LessEqualString = R"_LexStr_(<=)_LexStr_";
static inline constexpr std::string_view GreaterEqualString = R"_LexStr_(>=)_LexStr_";
static inline constexpr std::string_view RArrowString = R"_LexStr_(->)_LexStr_";
static inline constexpr std::string_view LArrowString = R"_LexStr_(<-)_LexStr_";
static inline constexpr std::string_view FatArrowString = R"_LexStr_(=>)_LexStr_";
static inline constexpr std::string_view DoublePeriodString = R"_LexStr_(..)_LexStr_";
static inline constexpr std::string_view DoublePeriodEqualString = R"_LexStr_(..=)_LexStr_";
static inline constexpr std::string_view DoubleQuestionEqualString = R"_LexStr_(??=)_LexStr_";
