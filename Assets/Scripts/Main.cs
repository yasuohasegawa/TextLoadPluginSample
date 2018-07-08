using UnityEngine;
using System;
using System.Runtime.InteropServices;
using System.Text;

public class Main : MonoBehaviour
{
    [DllImport("TextFileLoader")]
    private static extern IntPtr LoadText(IntPtr name);

    void Start()
    {
        string str1 = "C:\\Users\\yasuo\\Desktop\\WORKS_UNITY\\misc\\test.txt";
        IntPtr ptr1 = Marshal.StringToHGlobalAnsi(str1);
        IntPtr res = LoadText(ptr1);

        Debug.Log(Marshal.PtrToStringAnsi(res));

        Marshal.FreeHGlobal(ptr1);
        Marshal.FreeHGlobal(res);
    }

    void Update()
    {

    }

    void OnApplicationQuit()
    {

    }
}