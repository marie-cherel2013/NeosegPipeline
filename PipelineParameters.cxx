#include "PipelineParameters.h"

PipelineParameters::PipelineParameters()
{  
   m_prefix = "neo";

   m_newAtlas_default = true; 
   m_newAtlas = m_newAtlas_default;

   m_smoothing_values.push_back("gaussian");
   m_smoothing_values.push_back("curve evolution");
   m_smoothing_default=m_smoothing_values[0];
   m_smoothing=m_smoothing_default;

   m_smoothingSize_min=0;
   m_smoothingSize_max=6;
   m_smoothingSize_default=1;
   m_smoothingSize=m_smoothingSize_default;

   m_computingWeights_default=1;
   m_computingWeights=m_computingWeights_default;

   m_weightsModality_values.push_back("T1");
   m_weightsModality_values.push_back("T2");
   m_weightsModality_default=m_weightsModality_values[0];
   m_weightsModality=m_weightsModality_default;

   m_weightsRadius_min=0;
   m_weightsRadius_max=6;
   m_weightsRadius_default=3;
   m_weightsRadius=m_weightsRadius_default;

   m_usingFA_default = false; 
   m_usingFA = m_usingFA_default;

   m_usingAD_default = true; 
   m_usingAD = m_usingAD_default;

   m_computing3LabelsSeg_default = true; 
   m_computing3LabelsSeg = m_computing3LabelsSeg_default;

   m_overwriting_default=0;
   m_overwriting=m_overwriting_default;

   m_cleaningUp_default=1;
   m_cleaningUp=m_cleaningUp_default;

   m_computingSystem_values.push_back("local");
   m_computingSystem_values.push_back("killdevil");
   m_computingSystem_default=m_computingSystem_values[0];
   m_computingSystem=m_computingSystem_default;

   m_numberOfCores_min=0;
   m_numberOfCores_max=20;
   m_numberOfCores_default=1;
   m_numberOfCores=m_numberOfCores_default;

   m_antsParameters=new AntsParameters(); 

   m_neosegParameters=new NeosegParameters(); 

   m_executablePaths=new ExecutablePaths(); 

   m_executablePaths->setDefaultExecutablePath("SegPostProcessCLP");
   m_executablePaths->setDefaultExecutablePath("N4ITKBiasFieldCorrection");
   m_executablePaths->setDefaultExecutablePath("ANTS");
   m_executablePaths->setDefaultExecutablePath("ResampleVolume2");
   m_executablePaths->setDefaultExecutablePath("ImageMath");
   m_executablePaths->setDefaultExecutablePath("ITKTransformTools");
   m_executablePaths->setDefaultExecutablePath("dtiestim");
   m_executablePaths->setDefaultExecutablePath("dtiprocess");
   m_executablePaths->setDefaultExecutablePath("bet2");
   m_executablePaths->setDefaultExecutablePath("unu");
   m_executablePaths->setDefaultExecutablePath("InsightSNAP");
   m_executablePaths->setDefaultExecutablePath("HistogramMatching");
   m_executablePaths->setExecutablePath("SpreadFA", "/work/mcherel/project/neosegPipeline/spreadFA/bin/SpreadFA");
   m_executablePaths->setExecutablePath("neoseg", "/work/mcherel/project/neoseg/bin/bin_lessRefinement/neoseg");
}

// Checking Functions

bool PipelineParameters::isBetween(int value, int min, int max)
{
   if(value>min && value<max)
   {
      return true; 
   }
   return false; 
}

bool PipelineParameters::isBetween(double value, double min, double max)
{
   if(value>min && value<max)
   {
      return true; 
   }
   return false; 
}


bool PipelineParameters::isIn(QString item, std::vector<QString> vector)
{
   std::vector<QString>::iterator it; 
   for(it=vector.begin(); it!=vector.end(); ++it)
   {
      if(item.compare(*it, Qt::CaseInsensitive))
      {
         return true;
      }
   }
   return false; 
}

QFileInfoList PipelineParameters::find(QDir* dir, QString name)
{
   name = "*" + name + "*";
   QStringList* filter = new QStringList(name);
   QFileInfoList foundFile_list = dir->entryInfoList(*filter);

   return foundFile_list;
} 


//Suffix
void PipelineParameters::setPrefix(QString prefix) 
{
   m_prefix=prefix;
}
QString PipelineParameters::getPrefix() 
{
   return m_prefix;
}

// Output
bool PipelineParameters::checkOutput(QString output)
{
   return (QDir(output)).exists();
}
void PipelineParameters::setOutput(QString output) 
{
   m_output=output;
}
QString PipelineParameters::getOutput() 
{
   return m_output;
} 

// T1
bool PipelineParameters::checkT1(QString T1) 
{
   return (QFile(T1)).exists();
}
void PipelineParameters::setT1(QString T1)
{
   m_T1=T1;
}
QString PipelineParameters::getT1()
{
   return m_T1;
} 

// T2 
bool PipelineParameters::checkT2(QString T2)
{
   return (QFile(T2)).exists();
}
void PipelineParameters::setT2(QString T2)
{
   m_T2=T2;
}
QString PipelineParameters::getT2()
{
   return m_T2;
}

// Mask
bool PipelineParameters::checkMask(QString mask)
{
   return (QFile(mask)).exists();
}
void PipelineParameters::setMask(QString mask)
{
   m_mask=mask;
}
QString PipelineParameters::getMask()
{
   return m_mask;
}

// DWI
bool PipelineParameters::checkDWI(QString DWI) 
{
   return (QFile(DWI)).exists();
}
void PipelineParameters::setDWI(QString DWI)
{
   m_DWI=DWI;
}
QString PipelineParameters::getDWI()
{
   return m_DWI;
}

// b0
bool PipelineParameters::checkb0(QString b0)
{
   return (QFile(b0)).exists();
}
void PipelineParameters::setb0(QString b0)
{
   m_b0=b0;
}
QString PipelineParameters::getb0()
{
   return m_b0;
}

// Neo
void PipelineParameters::initializeNeo()
{
   m_neo.prefix = m_prefix;
   m_neo.T1 = m_T1; 
   m_neo.T2 = m_T2;
   m_neo.mask = m_mask; 
   m_neo.DWI = m_DWI; 
   m_neo.b0 = m_b0; 
}
void PipelineParameters::setNeo(Neo neo)
{
   m_neo=neo;
}
Neo PipelineParameters::getNeo()
{
   return m_neo;
}

// SkullStripping
void PipelineParameters::setSkullStripping(bool skullStripping)
{
   m_skullStripping=skullStripping;
}
bool PipelineParameters::getSkullStripping()
{
   return m_skullStripping;
}

// New Atlas
void PipelineParameters::setNewAtlas(bool newAtlas)
{
   m_newAtlas=newAtlas;
}
bool PipelineParameters::getNewAtlas()
{
   return m_newAtlas;
}

// Atlas
bool PipelineParameters::checkExistingAtlas(QString atlas)
{
   QDir* atlas_dir = new QDir(atlas);

   if(atlas_dir->exists())
   {
      QFileInfoList templateT1 = find(atlas_dir, "templateT1");
      QFileInfoList templateT2 = find(atlas_dir, "templateT2");

      QFileInfoList white = find(atlas_dir, "white");
      QFileInfoList gray = find(atlas_dir, "gray");
      QFileInfoList csf = find(atlas_dir, "csf");
      QFileInfoList rest = find(atlas_dir, "rest");

      if (templateT1.size()==1 && templateT2.size()==1 && white.size()==1 && gray.size()==1 && csf.size()==1 && rest.size()) 
      {
         return true;
      }
   }

   return false;
}
void PipelineParameters::setAtlas(QString atlas)
{
   m_atlas=atlas;
}
QString PipelineParameters::getAtlas()
{
   return m_atlas;
}

// Atlas Population Directory
bool PipelineParameters::checkAtlasPopulationDirectory(QString atlasPopulation_path)
{
   return (QDir(atlasPopulation_path)).exists();
}
void PipelineParameters::setAtlasPopulationDirectory(QString atlasPopulationDirectory)
{
   m_atlasPopulationDirectory=atlasPopulationDirectory;
}
QString PipelineParameters::getAtlasPopulationDirectory() 
{
   return m_atlasPopulationDirectory;
}

// Selected Atlases
void PipelineParameters::setSelectedAtlases(QStringList selectedAtlases) 
{
   m_selectedAtlases=selectedAtlases;
}
QStringList PipelineParameters::getSelectedAtlases() 
{
   return m_selectedAtlases;
}

// Atlas Population 
std::map<QString,QFileInfoList> PipelineParameters::findAtlasFiles(QString atlas_name)
{
   std::map<QString,QFileInfoList> atlasFiles;
 
   QDir* atlasPopulation_dir = new QDir(m_atlasPopulationDirectory);
   QString atlas_path = atlasPopulation_dir->filePath(atlas_name);

   QDir* atlas_dir = new QDir(atlas_path);

   atlasFiles.insert(std::pair<QString,QFileInfoList>("T1",find(atlas_dir, "T1")));
   atlasFiles.insert(std::pair<QString,QFileInfoList>("T2",find(atlas_dir, "T2")));
   atlasFiles.insert(std::pair<QString,QFileInfoList>("seg",find(atlas_dir, "seg")));
   atlasFiles.insert(std::pair<QString,QFileInfoList>("white",find(atlas_dir, "white")));
   atlasFiles.insert(std::pair<QString,QFileInfoList>("gray",find(atlas_dir, "gray")));
   atlasFiles.insert(std::pair<QString,QFileInfoList>("csf",find(atlas_dir, "csf")));

   return atlasFiles;
}

bool PipelineParameters::checkAtlas(QString atlas)
{ 
   std::map<QString,QFileInfoList> atlasFiles = findAtlasFiles(atlas);  

   if ((atlasFiles["T1"]).size() == 1 && (atlasFiles["T2"]).size() == 1)
   {
      // Hard segmentation
      if ((atlasFiles["seg"]).size() == 1)
      {
         return true;
      }

      // Soft segmentation
      if ((atlasFiles["white"]).size() == 1 && (atlasFiles["gray"]).size() == 1 && (atlasFiles["csf"]).size() == 1)
      {
         return true;
      }      
   }
   return false;
}
void PipelineParameters::initializeAtlasPopulation() 
{
   QStringList::const_iterator it;

   for (it = m_selectedAtlases.constBegin(); it != m_selectedAtlases.constEnd(); ++it) 
   {
      Atlas atlas;

      QDir* atlasPopulation_dir = new QDir(m_atlasPopulationDirectory);
      QString atlas_path = atlasPopulation_dir->filePath(*it);

      atlas.name=*it;

      std::map<QString,QFileInfoList> atlasFiles = findAtlasFiles(atlas_path); 

      atlas.T1 = (atlasFiles["T1"])[0].filePath();
      atlas.T2 = (atlasFiles["T2"])[0].filePath();

      if( (atlasFiles["seg"]).size()==1 )
      {
         atlas.seg = (atlasFiles["seg"])[0].filePath();
         atlas.probabilistic = 0;
      }


      if( (atlasFiles["white"]).size()==1 && (atlasFiles["gray"]).size()==1 && (atlasFiles["csf"]).size()==1 )
      {
         atlas.white=(atlasFiles["white"])[0].filePath();
         atlas.gray=(atlasFiles["gray"])[0].filePath();
         atlas.csf=(atlasFiles["csf"])[0].filePath();
         atlas.probabilistic=1;
      }

      m_atlasPopulation.push_back(atlas);
   } 
}
void PipelineParameters::setAtlasPopulation(std::vector<Atlas> atlasPopulation)
{
   m_atlasPopulation=atlasPopulation;
}
std::vector<Atlas> PipelineParameters::getAtlasPopulation()
{
   return m_atlasPopulation;
}

// Smoothing 
bool PipelineParameters::checkSmoothing(QString smoothing)
{
   return isIn(smoothing, m_smoothing_values);
}
QString PipelineParameters::getSmoothingFlag(QString regularizationType)
{
   if(regularizationType.compare("gauss", Qt::CaseInsensitive) || regularizationType.compare("gaussian", Qt::CaseInsensitive))
   {
      return "gauss";
   }

   if(regularizationType.compare("curveEvolution", Qt::CaseInsensitive) || regularizationType.compare("curve evolution", Qt::CaseInsensitive))
   {
      return "curveEvol";
   }
   
   return NULL;
}
void PipelineParameters::setSmoothing(QString smoothing)
{
   m_smoothing=getSmoothingFlag(smoothing);
}
QString PipelineParameters::getSmoothing()
{
   return m_smoothing;
} 

// Smoothing Size
bool PipelineParameters::checkSmoothingSize(double smoothingSize)
{
   return isBetween(smoothingSize, m_smoothingSize_min, m_smoothingSize_max);
}
void PipelineParameters::setSmoothingSize(double smoothingSize) 
{
   m_smoothingSize=smoothingSize;
}
double PipelineParameters::getSmoothingSize()
{
   return m_smoothingSize;
}

// Computing Weights
void PipelineParameters::setComputingWeights(int computingWeights)
{
   m_computingWeights=computingWeights;
}
bool PipelineParameters::getComputingWeights()
{
   return m_computingWeights;
}

// Weights Modality 
bool PipelineParameters::checkWeightsModality(QString weightsModality)
{
   return isIn(weightsModality, m_weightsModality_values);
}
void PipelineParameters::setWeightsModality(QString weightsModality)
{
   m_weightsModality=weightsModality;
}
QString PipelineParameters::getWeightsModality()
{
   return m_weightsModality;
}

// Weights Radius 
bool PipelineParameters::checkWeightsRadius(double weightsRadius)
{
   return isBetween(weightsRadius, m_weightsRadius_min, m_weightsRadius_max);
}
void PipelineParameters::setWeightsRadius(double weightsRadius)
{
   m_weightsRadius=weightsRadius;
}
double PipelineParameters::getWeightsRadius()
{
   return m_weightsRadius;
}

// Including FA
void PipelineParameters::setIncludingFA(bool includingFA)
{
   m_includingFA = includingFA;
}
bool PipelineParameters::getIncludingFA()
{
   return m_includingFA;
}

// Using FA
void PipelineParameters::setUsingFA(bool usingFA)
{
   m_usingFA = usingFA; 
}
bool PipelineParameters::getUsingFA()
{
   return m_usingFA; 
}

// Using AD
void PipelineParameters::setUsingAD(bool usingAD)
{
   m_usingAD = usingAD; 
}
bool PipelineParameters::getUsingAD()
{
   return m_usingAD; 
}


// Computing 3-Labels Segmentation
void PipelineParameters::setComputing3LabelsSeg(bool computing3LabelsSeg)
{
   m_computing3LabelsSeg = computing3LabelsSeg;
}
bool PipelineParameters::getComputing3LabelsSeg()
{
   return m_computing3LabelsSeg;
} 

// Overwriting
void PipelineParameters::setOverwriting(bool overwriting)
{
   m_overwriting=overwriting;
} 
bool PipelineParameters::getOverwriting()
{
   return m_overwriting;
}

// Cleaning-Up
void PipelineParameters::setCleaningUp(bool cleaningUp)
{
   m_cleaningUp=cleaningUp;
}
bool PipelineParameters::getCleaningUp()
{
   return m_cleaningUp;
}

// Computing System
bool PipelineParameters::checkComputingSystem(QString computingSystem)
{
   return isIn(computingSystem, m_computingSystem_values);
}
void PipelineParameters::setComputingSystem(QString computingSystem)
{
   m_computingSystem=computingSystem;
}
QString PipelineParameters::getComputingSystem()
{
   return m_computingSystem;
}

// Number Of Cores 
bool PipelineParameters::checkNumberOfCores(int numberOfCores)
{
   return isBetween(numberOfCores, m_numberOfCores_min, m_numberOfCores_max);
}
void PipelineParameters::setNumberOfCores(int numberOfCores)
{
   m_numberOfCores=numberOfCores;
}
int PipelineParameters::getNumberOfCores()
{
   return m_numberOfCores;
}

// ANTS Parameters
AntsParameters* PipelineParameters::getAntsParameters()
{
   return m_antsParameters;
}

// Neoseg Parameters
NeosegParameters* PipelineParameters::getNeosegParameters()
{
   return m_neosegParameters;
}

// Executable Paths 
ExecutablePaths* PipelineParameters::getExecutablePaths()
{
   return m_executablePaths;
}

// Segmentation
void PipelineParameters::setSegmentation(QString segmentation) 
{
   m_segmentation=segmentation;
}
QString PipelineParameters::getSegmentation()
{
   return m_segmentation;
}



