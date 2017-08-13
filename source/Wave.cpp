#include "Wave.h"

WAV_DATA readWave(string file) {

	cout<<"\n are you ready";
	wav_hdr wavHeader;
	WAV_DATA wavData;
	int headerSize = sizeof(wavHeader);
	const char* filepath = file.c_str();
	cout << "\n input file: "<<filepath<<endl;

    readHeader(wavHeader,file);

	ifstream ifs;
	ifs.open(filepath);
    cout<<"\n step 1";
	if (!ifs)
    {
        cout<<"\n step 1.1";
        fprintf(stderr, "Unable to open wave file: %s\n", filepath);
        exit(1);
    } else {

    }
    cout<<"\n step 2";

    //read the header file
    //ifs.read((char*)&wavHeader, headerSize);
    cout<<"\n step 3";
    std::vector<short> lData;

    while(!ifs.eof()){
    	short buffer; // use short by default 16bit per sample
    	ifs.read((char*)buffer, sizeof(buffer));
    	lData.push_back(buffer);
    }
    cout<<"\n step 4";

    wavData.wavHeader = wavHeader;
    wavData.lData = lData;
    ifs.close();
    return wavData;
}

void writeWave(WAV_DATA wavData, string outfile){
	const char* filepath = outfile.c_str();
    writeHeader(wavData.wavHeader,filepath);

    std::ofstream ofs;
	//int headerSize = sizeof(wavData.wavHeader);
 	ofs.open(outfile, std::ios::out|std::ios::binary|std::ios::trunc);
  	if (!ofs) {
    	std::cout << "cannot create file "<< outfile;
        exit(1);
    }

    if(wavData.lData.empty()) {
    	std::cout << "data is empty "<< outfile;
        exit(1);
    }

    //write header
    //ofs.write((char*)wavData.wavHeader, headerSize);

    //write data
    std::vector<short>::iterator lit = wavData.lData.begin();
    while(lit != wavData.lData.end()) {
    	short buffer;
    	if (lit != wavData.lData.end()){
      		buffer = *lit;
      		lit++;
    		}
    	else{
      		buffer = 0;
		}
    	ofs.write((char*)buffer, sizeof(buffer));
    }
    ofs.close();
}

void readHeader(wav_hdr &wavHeader, string file) {
    const char* filepath = file.c_str();
    ifstream ifs;
    ifs.open(filepath,ios::in|ios::binary);
    cout<<"\n read 1";
    ifs.open(filepath, std::ios::out|std::ios::binary|std::ios::trunc);
    ifs.read((char*)wavHeader.riffID, sizeof(wavHeader.riffID));

    ifs.read((char*)wavHeader.size, sizeof(wavHeader.size));
    ifs.read((char*)wavHeader.wavID, sizeof(wavHeader.wavID));
    ifs.read((char*)wavHeader.fmtID, sizeof(wavHeader.fmtID));
    ifs.read((char*)wavHeader.fmtSize, sizeof(wavHeader.fmtSize));
    ifs.read((char*)wavHeader.format, sizeof(wavHeader.format));
    ifs.read((char*)wavHeader.channels, sizeof(wavHeader.channels));
    ifs.read((char*)wavHeader.sampleRate, sizeof(wavHeader.sampleRate));
    ifs.read((char*)wavHeader.bytePerSec, sizeof(wavHeader.bytePerSec));
    ifs.read((char*)wavHeader.blockSize, sizeof(wavHeader.blockSize));
    ifs.read((char*)wavHeader.bit, sizeof(wavHeader.bit));
    ifs.read((char*)wavHeader.dataID, sizeof(wavHeader.dataID));
    ifs.read((char*)wavHeader.dataSize, sizeof(wavHeader.dataSize));
    ifs.close();
    cout<<"\n read 1 done";
    writeHeader(wavHeader, file + "1");
}

void writeHeader(wav_hdr wavHeader, string file) {
    std::ofstream ofs;
    const char* filepath = file.c_str();

    ofs.open(filepath, std::ios::out|std::ios::binary|std::ios::trunc);
    ofs.write((char*)wavHeader.riffID, sizeof(wavHeader.riffID));
    ofs.write((char*)wavHeader.size, sizeof(wavHeader.size));
    ofs.write((char*)wavHeader.wavID, sizeof(wavHeader.wavID));
    ofs.write((char*)wavHeader.fmtID, sizeof(wavHeader.fmtID));
    ofs.write((char*)wavHeader.fmtSize, sizeof(wavHeader.fmtSize));
    ofs.write((char*)wavHeader.format, sizeof(wavHeader.format));
    ofs.write((char*)wavHeader.channels, sizeof(wavHeader.channels));
    ofs.write((char*)wavHeader.sampleRate, sizeof(wavHeader.sampleRate));
    ofs.write((char*)wavHeader.bytePerSec, sizeof(wavHeader.bytePerSec));
    ofs.write((char*)wavHeader.blockSize, sizeof(wavHeader.blockSize));
    ofs.write((char*)wavHeader.bit, sizeof(wavHeader.bit));
    ofs.write((char*)wavHeader.dataID, sizeof(wavHeader.dataID));
    ofs.write((char*)wavHeader.dataSize, sizeof(wavHeader.dataSize));
    ofs.close();
}