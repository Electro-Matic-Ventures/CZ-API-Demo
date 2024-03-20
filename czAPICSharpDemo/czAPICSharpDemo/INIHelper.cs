using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace Demo
{
    public class INIHelper
    {
        [DllImport("kernel32", CharSet = CharSet.Ansi)]
        private static extern long WritePrivateProfileString(string section, string key, string val, string filepath);
        [DllImport("kernel32", CharSet = CharSet.Ansi)]
        private static extern int GetPrivateProfileString(string section, string key, string def, StringBuilder retval, int size, string filePath);

        //ini文件名称
        public static string inifilename = "Config.ini";
        //获取ini文件路径
        public static string inifilepath = Directory.GetCurrentDirectory() + "\\" + inifilename;

        public static string GetValue(string section, string key)
        {
            StringBuilder s = new StringBuilder(1024);
            GetPrivateProfileString(section, key, "", s, 1024, inifilepath);
            return s.ToString();
        }


        public static void SetValue(string section, string key, string value)
        {
            try
            {
                WritePrivateProfileString(section, key, value, inifilepath);
            }
            catch (Exception ex)
            {
                //throw ex;
            }
        }
    }
}
