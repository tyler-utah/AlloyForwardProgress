/* Alloy Analyzer 4 -- Copyright (c) 2006-2009, Felix Chang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

package edu.mit.csail.sdg.alloy4whole;

import java.io.*;
import java.io.File;
import edu.mit.csail.sdg.alloy4.A4Reporter;
import edu.mit.csail.sdg.alloy4.ConstList;
import edu.mit.csail.sdg.alloy4.Err;
import edu.mit.csail.sdg.alloy4.ErrorWarning;
import edu.mit.csail.sdg.alloy4.SafeList;
import edu.mit.csail.sdg.ast.Command;
import edu.mit.csail.sdg.ast.Module;
import edu.mit.csail.sdg.ast.Sig;
import edu.mit.csail.sdg.parser.CompUtil;
import edu.mit.csail.sdg.alloy4.Util;
import edu.mit.csail.sdg.translator.A4Options;
import edu.mit.csail.sdg.translator.A4Solution;
import edu.mit.csail.sdg.translator.TranslateAlloyToKodkod;
import edu.mit.csail.sdg.alloy4viz.VizGUI;
import edu.mit.csail.sdg.alloy4viz.VizState;
import edu.mit.csail.sdg.alloy4viz.AlloyInstance;
import edu.mit.csail.sdg.alloy4viz.VizGraphPanel;
import edu.mit.csail.sdg.alloy4graph.GraphViewer;
import edu.mit.csail.sdg.ast.CommandScope;

import edu.mit.csail.sdg.alloy4viz.StaticInstanceReader;
import java.io.IOException;

/** This class demonstrates how to access Alloy4 via the compiler methods. */

public final class CreateTests {
    /*
     * Execute every command in every file.
     *
     * This method parses every file, then execute every command.
     *
     * If there are syntax or type errors, it may throw
     * a ErrorSyntax or ErrorType or ErrorAPI or ErrorFatal exception.
     * You should catch them and display them,
     * and they may contain filename/line/column information.
     */
    public static void main(String[] args) throws Err {

        // The visualizer (We will initialize it to nonnull when we visualize an Alloy solution)
        AlloyInstance myInstance = null;
        VizGUI viz = null;
        VizState myState=null;
        VizGraphPanel myGraphPanel=null;

        // Alloy4 sends diagnostic messages and progress reports to the A4Reporter.
        // By default, the A4Reporter ignores all these events (but you can extend the A4Reporter to display the event for the user)
        A4Reporter rep = new A4Reporter() {
            // For example, here we choose to display each "warning" by printing it to System.out
            @Override public void warning(ErrorWarning msg) {
                System.out.print("Relevance Warning:\n"+(msg.toString().trim())+"\n\n");
                System.out.flush();
            }
        };

        if (args.length != 2){
            System.out.print("Need exactly two arguments. Folder name and .als file location.");
            System.out.flush();
            return;
        }

        String filename = args[1];
        // Parse+typecheck the model
        System.out.println("=========== Parsing+Typechecking "+filename+" =============");
        Module world = CompUtil.parseEverything_fromFile(rep, null, filename);

        // Choose some default options for how you want to execute the commands
        A4Options options = new A4Options();

        options.solver = A4Options.SatSolver.GlucoseJNI;

        int i = 0;
        for (Command command: world.getAllCommands()) {
            // Execute the command
            System.out.println("============ Command "+command+": ============");
            A4Solution ans = TranslateAlloyToKodkod.execute_command(rep, world.getAllReachableSigs(), command, options);

            File file = new File("../"+ args[0]);
            boolean bool = file.mkdir();

            // If satisfiable...
            while (ans.satisfiable()) {
                // You can query "ans" to find out the values of each set or type.
                // This can be useful for debugging.
                //
                // You can also write the outcome to an XML file
                File file2 = new File("../"+ args[0]+"/"+i);
                bool = file2.mkdir();

                ans.writeXML("../"+ args[0]+"/"+i +"/" + i + ".xml");

                // We convert the XML into TXT and check if it is unique
                // Else we delete files and folder and continue
                try{
                    Process p = Runtime.getRuntime().exec("python Converter.py "+ args[0] +" "+i);
                    // We wait for output to know conversion is done
                    BufferedReader in = new BufferedReader(new InputStreamReader(p.getInputStream()));
                    int ret = new Integer(in.readLine()).intValue();

                    // We now run the deduplicator
                    p = Runtime.getRuntime().exec("python Deduplicate.py "+ args[0] +" "+i);
                    in = new BufferedReader(new InputStreamReader(p.getInputStream()));
                    ret = new Integer(in.readLine()).intValue();

                    // If file is duplicate
                    if (ret == 1){
                        // Delete files/folders
                        File file3 = new File("../"+ args[0]+"/"+i +"/" + i + ".xml");
                        File file4 = new File("../"+ args[0]+"/"+i +"/" + i + ".txt");
                        File file5 = new File("../"+ args[0]+"/"+i +"/" + i + "_simple.txt");
                        file5.delete();
                        file4.delete();
                        file3.delete();
                        file2.delete();

                        ans = ans.next();
                        continue;
                    }
                }
                catch (Exception e){}

                File f = new File("../"+ args[0]+"/"+i +"/" + i + ".xml");
                myInstance = StaticInstanceReader.parseInstance(f);
                myState=new VizState(myInstance);
                try {
                    myState.loadPaletteXML("test_theme.thm");
                } catch (IOException ex) {
                    // This should not happen. But we continue with an "unthemed" DOT file.
                }
                myGraphPanel=new VizGraphPanel(myState, false);
                Util.writeAll("../"+ args[0]+"/"+i +"/" + i + ".dot", myGraphPanel.toDot());

                ans = ans.next();
                i++;
                
            }
        }
    }
}

 