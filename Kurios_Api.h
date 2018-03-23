
/// <summary>
/// <p>load uart library</p>
/// </summary>
/// <returns>non-negtive number: succeed; negtive number : failed.</returns>
int Init();

/// <summary>
/// list all the possible port on this computer.
/// </summary>
/// <param name="c">returned string buffer</param>
/// <returns>non-negtive number: number of device in the list; negtive number : failed.</returns>
int fnKurios_List(char* c);

/// <summary>
/// <p>open port function.</p>
/// </summary>
/// <param name="sn">serial number of the device to be opened, use fnUART_LIBRARY_list function to get exist list first.</param>
/// <returns> non-negtive number: hdl number returned successfully; negtive number : failed.</returns>
int fnKurios_Open(char* sn);

/// <summary>
/// <p>close current opend port.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <returns> 0: success; negtive number : failed.</returns>
int fnKurios_Close(int hdl);

/// <summary>
/// <p>Get device ID.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="c">returned string buffer</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_GetID(int hdl,char *c);

/// <summary>
/// <p>set bandwidth mode of Kurios device.</p>
/// <p>Black = 1,Wide = 2,Medium = 4,Narrow= 8</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="n">input number of bandwidth mode</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_SetBandwidthMode(int hdl,int n);

/// <summary>
/// <p>set Output mode of Kurios device.</p>
/// <p>Manual = 1,Internal Trigger = 2,External Trigger = 3,Internal Analog = 4,External Analog = 5</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="n">input number of Output mode</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_SetOutputMode(int hdl,int n);

/// <summary>
/// <p>set Wavelength.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="n">input number of Wavelength</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_SetWavelength(int hdl,int n);

/// <summary>
/// <p>Get Wavelength.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="c">returned string buffer</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_GetWavelength(int hdl,char *c);

/// <summary>
/// <p>Get Output Mode.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="c">returned string buffer</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_GetOutputMode(int hdl,char *c);

/// <summary>
/// <p>Get Bandwidth Mode.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="c">returned string buffer</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_GetBandwidthMode(int hdl,char *c);

/// <summary>
/// <p>set Sequence.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="n">the index in the Sequence(start from 1)</param>
/// <param name="wl">the wavelength of sequence</param>
/// <param name="interval">the interval of sequence</param>
/// <param name="bandwidth">the bandwidth of sequence</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_SetSequence(int hdl,int n,int wl,int interval, int bandwidth);

/// <summary>
/// <p>Get Sequence.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="n">the index in the Sequence(start from 1)</param>
/// <param name="c">returned string buffer</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_GetSequence(int hdl,int n,char *c);

/// <summary>
/// <p>Get all Sequence.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="c">returned string buffer</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_GetAllSequence(int hdl,char *c);

/// <summary>
/// <p>Insert sequence.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="n">the index in the Sequence(start from 1)</param>
/// <param name="wl">the wavelength of sequence</param>
/// <param name="interval">the interval of sequence</param>
/// <param name="bandwidth">the bandwidth of sequence</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_InsertSequence(int hdl,int n,int wl,int interval, int bandwidth);

/// <summary>
/// <p>Delete sequence.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="n">the index in the Sequence(start from 1)</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xEC: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
int fnKurios_DeleteSequence(int hdl,int n);

