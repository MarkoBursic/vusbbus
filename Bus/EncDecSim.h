//---------------------------------------------------------------------------
#ifndef EncDecSimH
#define EncDecSimH
//---------------------------------------------------------------------------
typedef UCHAR   BYTE;
typedef USHORT  WORD;
typedef ULONG   DWORD;
//---------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif  
//---------------------------------------------------------------------------
// ��������� � ����������� � ���������� �����
typedef struct {
    // ��������� �����
    BYTE    columnMask;
    BYTE    cryptInitVect;
    BYTE    secTable[8];
    // ������� �������� ������� ST
    BYTE    isInvSecTab;
    // ����������� ������� �������� ��� ���� �������� �����
    DWORD   prepNotMask;
    // ������� ��������� LFSR
    DWORD   curLFSRState;
} KEY_INFO;
//---------------------------------------------------------------------------
void InitTransform2(KEY_INFO *keyInfo);
DWORD Transform2(DWORD in5Bit, KEY_INFO *keyInfo);
void Encode(DWORD *bufPtr, DWORD *nextBufPtr, KEY_INFO *keyInfo);
void Decode(DWORD *bufPtr, DWORD *nextBufPtr, KEY_INFO *keyInfo);
void GetCode(unsigned short seed, DWORD *bufPtr, BYTE *secTable);
void __fastcall HashDWORD(DWORD *Data, BYTE *edStruct);
//---------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif  
//---------------------------------------------------------------------------
#endif

